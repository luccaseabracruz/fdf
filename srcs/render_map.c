/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:51:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/04 19:45:10 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		dst = dt->addr + (y * dt->line_length + x * (dt->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static t_point	apply_grid_step(t_point point, double grid_step)
{
	point.x *= grid_step;
	point.y *= grid_step;
	point.z *= grid_step;
	return (point);
}

void	render_map(t_data *dt)
{
	int		i;
	t_point	point;

	i = 0;
	while (i < dt->map->size)
	{
		point = dt->map->p_arr[i];
		point = apply_grid_step(point, dt->view.grid_step);
		// set_rotation_x(&dt->view, degrees_to_radians(ISO_INIT_ANG_X));
		// point = mat_point_mul(dt->view.rotation, point);
		set_rotation_y(&dt->view, degrees_to_radians(ISO_INIT_ANG_Y));
		point = mat_point_mul(dt->view.rotation, point);
		pixel_put(dt, point.x, point.y, point.color);
		i++;
	}
}
