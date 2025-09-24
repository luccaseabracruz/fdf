/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:51:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/24 19:54:27 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

void	set_limits(t_data *dt)
{
	int			i;
	t_limits	*lim;

	lim = &dt->view.limits;
	lim->x_min = INT_MAX;
	lim->x_max = INT_MIN;
	lim->y_min = INT_MAX;
	lim->y_max = INT_MIN;
	i = 0;
	while (i < dt->map->size)
	{
		if (lim->x_min > dt->map->proj_arr[i].x)
			lim->x_min = dt->map->proj_arr[i].x;
		if (lim->x_max < dt->map->proj_arr[i].x)
			lim->x_max = dt->map->proj_arr[i].x;
		if (lim->y_min > dt->map->proj_arr[i].y)
			lim->y_min = dt->map->proj_arr[i].y;
		if (lim->y_max < dt->map->proj_arr[i].y)
			lim->y_max = dt->map->proj_arr[i].y;
		i++;
	}
}

void	project_points(t_data *dt)
{
	int		i;
	t_point	*point;
	t_point	*proj;
	t_view	*view;

	view = &dt->view;
	i = 0;
	while (i < dt->map->size)
	{
		point = &dt->map->p_arr[i];
		proj = &dt->map->proj_arr[i];
		proj->x = point->x * view->grid_step * view->zoom;
		proj->y = point->y * view->grid_step * view->zoom;
		proj->z = point->z * view->grid_step * view->zoom * view->z_scaler;
		proj->color = point->color;
		i++;
	}
	set_limits(dt);
	view->center.x = (view->limits.x_max + view->limits.x_min) / 2;
	view->center.y = (view->limits.y_max + view->limits.y_min) / 2;
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
