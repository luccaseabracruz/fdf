/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:43:17 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 12:15:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/**
 * @brief Plot a pixel at the given coordinates.
 *
 * This helper function writes a single pixel to the image buffer
 * if the coordinates are inside the window bounds.
 *
 * @param dt    Main program data containing image buffer info.
 * @param x     X coordinate of the pixel.
 * @param y     Y coordinate of the pixel.
 * @param color Color value to write (ARGB).
 */
static void	pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = dt->addr + (y * dt->line_length + x * (dt->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

/**
 * @brief Initialize a Bresenham line drawing context.
 *
 * Prepares the delta values, step directions, and endpoints
 * needed for the Bresenham algorithm.
 *
 * @param b_dt Pointer to a Bresenham context struct.
 * @param p1   Starting point of the line.
 * @param p2   Ending point of the line.
 */
static void	init_bresenham(t_bresenham *b_dt, t_point p1, t_point p2)
{
	ft_bzero(b_dt, sizeof(b_dt));
	b_dt->dx = absolute(p2.x - p1.x);
	b_dt->dy = absolute(p2.y - p1.y);
	if (p1.x > p2.x)
		b_dt->xstep = -1;
	else
		b_dt->xstep = 1;
	if (p1.y > p2.y)
		b_dt->ystep = -1;
	else
		b_dt->ystep = 1;
	b_dt->p1 = p1;
	b_dt->p2 = p2;
}

/**
 * @brief Draw a shallow line using Bresenham's algorithm.
 *
 * Used when the line slope is less than 1.
 *
 * @param dt   Main program data containing image buffer info.
 * @param b_dt Bresenham line context initialized with @ref init_bresenham.
 * 
 * Local variables:
 * - `x`: Current X coordinate during drawing.
 * - `y`: Current Y coordinate during drawing.
 * - `p`: Decision parameter that determines when to step in X.
 * - `i`: Step counter used to traverse the line.
 * - `cur_color`: Interpolated color at the current step.
 */
static void	shallow_line(t_data *dt, t_bresenham b_dt)
{
	int	x;
	int	y;
	int	p;
	int	i;
	int	cur_color;

	x = b_dt.p1.x;
	y = b_dt.p1.y;
	p = 2 * b_dt.dx - b_dt.dy;
	i = 0;
	while (i < b_dt.dy)
	{
		cur_color = color_between(b_dt, (float)i / b_dt.dy);
		pixel_put(dt, x, y, cur_color);
		y += b_dt.ystep;
		if (p < 0)
			p += 2 * b_dt.dx;
		else
		{
			p += 2 * (b_dt.dx - b_dt.dy);
			x += b_dt.xstep;
		}
		i++;
	}
}

/**
 * @brief Draw a steep line using Bresenham's algorithm.
 *
 * Used when the line slope is greater than or equal to 1.
 *
 * @param dt   Main program data containing image buffer info.
 * @param b_dt Bresenham line context initialized with @ref init_bresenham.
 * 
 * Local variables:
 * - `x`: Current X coordinate during drawing.
 * - `y`: Current Y coordinate during drawing.
 * - `p`: Decision parameter that determines when to step in X.
 * - `i`: Step counter used to traverse the line.
 * - `cur_color`: Interpolated color at the current step.
 */
static void	steep_line(t_data *dt, t_bresenham b_dt)
{
	int	x;
	int	y;
	int	p;
	int	i;
	int	cur_color;

	x = b_dt.p1.x;
	y = b_dt.p1.y;
	p = 2 * b_dt.dy - b_dt.dx;
	i = 0;
	while (i < b_dt.dx)
	{
		cur_color = color_between(b_dt, (float)i / b_dt.dx);
		pixel_put(dt, x, y, cur_color);
		x += b_dt.xstep;
		if (p < 0)
			p += 2 * b_dt.dy;
		else
		{
			p += 2 * (b_dt.dy - b_dt.dx);
			y += b_dt.ystep;
		}
		i++;
	}
}

/**
 * @brief Draw a line between two points using Bresenham's algorithm.
 *
 * Chooses between @ref shallow_line and @ref steep_line
 * depending on the line slope.
 *
 * @param dt Main program data containing image buffer info.
 * @param p1 Starting point of the line.
 * @param p2 Ending point of the line.
 *
 * Local variables:
 * - `b_dt`: The Bresenham context holding deltas, steps, and endpoints.
 */
void	bresenham_line(t_data *dt, t_point p1, t_point p2)
{
	t_bresenham	b_dt;

	init_bresenham(&b_dt, p1, p2);
	if (b_dt.dx >= b_dt.dy)
		steep_line(dt, b_dt);
	else
		shallow_line(dt, b_dt);
}
