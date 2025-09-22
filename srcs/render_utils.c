/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:51:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/22 16:29:14 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

void	project_points(t_data *dt)
{
	int		i;
	t_point	*point;
	t_point	*proj;

	i = 0;
	while (i < dt->map->size)
	{
		point = &dt->map->p_arr[i];
		proj = &dt->map->proj_arr[i];
		proj->x = point->x * dt->view.grid_step * dt->view.zoom;
		proj->y = point->y * dt->view.grid_step * dt->view.zoom;
		proj->z = point->z * dt->view.grid_step * dt->view.zoom * Z_SCALER;
		proj->color = point->color;
		i++;
	}
	set_limits(dt);
	dt->view.center.x = (dt->view.limits.x_max + dt->view.limits.x_min) / 2;
	dt->view.center.y = (dt->view.limits.y_max + dt->view.limits.y_min) / 2;
}

void	centralize(t_data *dt)
{
	int			i;
	t_point		center_offset;

	set_limits(dt);
	center_offset.x = (WIN_W / 2) - dt->view.center.x;
	center_offset.y = (WIN_H / 2) - dt->view.center.y;
	i = 0;
	while (i < dt->map->size)
	{
		dt->map->proj_arr[i].x += center_offset.x;
		dt->map->proj_arr[i].y += center_offset.y;
		dt->map->proj_arr[i].x += dt->view.pan_offset.x;
		dt->map->proj_arr[i].y += dt->view.pan_offset.y;
		i++;
	}
}

void	draw_lines(t_data *dt)
{
	t_point	*proj_arr;
	t_point	p1;
	int		i;
	int		j;

	proj_arr = dt->map->proj_arr;
	i = 0;
	while (i < dt->map->rows)
	{
		j = 0;
		while (j < dt->map->cols)
		{
			p1 = proj_arr[(i * dt->map->cols) + j];
			if (j < dt->map->cols - 1)
				bresenham_line(dt, p1, proj_arr[(i * dt->map->cols) + j + 1]);
			if (i < dt->map->rows - 1)
				bresenham_line(dt, p1, proj_arr[((i + 1) * dt->map->cols) + j]);
			j++;
		}
		i++;
	}
}
