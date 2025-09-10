/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:43:17 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/10 22:26:01 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		dst = dt->addr + (y * dt->line_length + x * (dt->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
	else
		ft_printf("OUT OF BOUNDRIES:\n   X: %d\n   Y: %d\n\n", x, y);
}

static void	init_bresenham(t_bresenham *b_dt, t_point p1, t_point p2)
{
	ft_bzero(b_dt, sizeof(b_dt));
	b_dt->dx = absolute(p2.x - p1.x);
	b_dt->dy = absolute(p2.y - p1.y);
	b_dt->m = b_dt->dy / b_dt->dx;
	if (p1.x > p2.x)
		b_dt->xstep = -1;
	else
		b_dt->xstep = 1;
	if (p1.y > p2.y)
		b_dt->ystep = -1;
	else	
		b_dt->ystep = 1;
}

void	bresenham_line(t_data *dt, t_point p1, t_point p2)
{
	t_bresenham	b_dt;
	int			p;
	int			x;
	int			y;
	int			i;

	init_bresenham(&b_dt, p1, p2);
	x = p1.x;
	y = p1.y;
	i = 0;
	if (b_dt.dx >= b_dt.dy)
	{
		p = 2 * b_dt.dy - b_dt.dx;
		while (i < b_dt.dx)
		{
			pixel_put(dt, x, y, p1.color);
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
	else
	{
		p = 2 * b_dt.dx - b_dt.dy;
		while (i < b_dt.dy)
		{
			pixel_put(dt, x, y, p1.color);
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
}
