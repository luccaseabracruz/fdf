/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:51:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/03 15:54:13 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	dst = dt->addr + (y * dt->line_length + x * (dt->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_point	rotate_point(t_view view, t_point point)
{

}

void	render_map(t_data *dt)
{
	int		i;
	t_point	point;
	t_point	rotated;

	i = 0;
	while (i < dt->map->size)
	{
		point = dt->map->p_arr[i];
		rotated = rotate_point(dt->view, point)
		pixel_put(dt, point.x_iso, point.y_iso, point.color);
		i++;
	}
}
