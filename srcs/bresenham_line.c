/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:43:17 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/24 16:16:48 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = dt->addr + (y * dt->line_length + x * (dt->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

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

void	bresenham_line(t_data *dt, t_point p1, t_point p2)
{
	t_bresenham	b_dt;

	init_bresenham(&b_dt, p1, p2);
	if (b_dt.dx >= b_dt.dy)
		steep_line(dt, b_dt);
	else
		shallow_line(dt, b_dt);
}
