/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:51:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/30 18:46:29 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	dst = dt->addr + (y * dt->line_length + x * (dt->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_map(t_data *dt)
{
	int		i;
	t_point	point;

	i = 0;
	while (i < dt->map->point_count)
	{
		point = dt->map->points[i];
		pixel_put(dt, point.x_iso, point.y_iso, point.color);
		i++;
	}
}
