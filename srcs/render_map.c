/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:51:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/18 17:37:55 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

static void	set_limits(t_data *dt)
{
	int		i;

	i = 0;
	while (i < dt->map->size)
	{
		if (dt->view.limits.x_min > dt->map->proj_arr[i].x)
			dt->view.limits.x_min = dt->map->proj_arr[i].x;
		if (dt->view.limits.x_max < dt->map->proj_arr[i].x)
			dt->view.limits.x_max = dt->map->proj_arr[i].x;
		if (dt->view.limits.y_min > dt->map->proj_arr[i].y)
			dt->view.limits.y_min = dt->map->proj_arr[i].y;
		if (dt->view.limits.y_max < dt->map->proj_arr[i].y)
			dt->view.limits.y_max = dt->map->proj_arr[i].y;
		i++;
	}
}

static void	project_points(t_data *dt)
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
		set_rotation_x(&dt->view);
		*proj = mat_point_mul(dt->view.rotation, *proj);
		set_rotation_y(&dt->view);
		*proj = mat_point_mul(dt->view.rotation, *proj);
		set_rotation_z(&dt->view);
		*proj = mat_point_mul(dt->view.rotation, *proj);
		i++;
	}
}

static void	centralize(t_data *dt)
{
	int			i;
	t_limits	lim;
	t_point		center;
	t_point		offset;

	lim = dt->view.limits;
	center.x = lim.x_max - ((lim.x_max - lim.x_min) / 2);
	center.y = lim.y_max - ((lim.y_max - lim.y_min) / 2);
	offset.x = (WIN_W / 2) - center.x;
	offset.y = (WIN_H / 2) - center.y;
	i = 0;
	while (i < dt->map->size)
	{
		dt->map->proj_arr[i].x += offset.x;
		dt->map->proj_arr[i].y += offset.y;
		i++;
	}
}

static void	draw_lines(t_data *dt)
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

void	render_map(t_data *dt)
{
	project_points(dt);
	set_limits(dt);
	centralize(dt);
	draw_lines(dt);
	mlx_put_image_to_window(dt->mlx, dt->mlx_win, dt->mlx_img, 0, 0);
}
