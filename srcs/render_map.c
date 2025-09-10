/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:51:00 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/07 17:03:14 by lseabra-         ###   ########.fr       */
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
		if (dt->view.limits.x_min > dt->map->p_arr[i].x)
			dt->view.limits.x_min = dt->map->p_arr[i].x;
		if (dt->view.limits.x_max < dt->map->p_arr[i].x)
			dt->view.limits.x_max = dt->map->p_arr[i].x;
		if (dt->view.limits.y_min > dt->map->p_arr[i].y)
			dt->view.limits.y_min = dt->map->p_arr[i].y;
		if (dt->view.limits.y_max < dt->map->p_arr[i].y)
			dt->view.limits.y_max = dt->map->p_arr[i].y;
		if (dt->view.limits.z_min > dt->map->p_arr[i].z)
			dt->view.limits.z_min = dt->map->p_arr[i].z;
		if (dt->view.limits.z_max < dt->map->p_arr[i].z)
			dt->view.limits.z_max = dt->map->p_arr[i].z;
		i++;
	}
}

static void	project_points(t_data *dt)
{
	int	i;
	t_point	*point;

	i = 0;
	while (i < dt->map->size)
	{
		point = &dt->map->p_arr[i];
		point->x *= dt->view.grid_step;
		point->y *= dt->view.grid_step;
		point->z *= dt->view.grid_step * Z_SCALER;
		set_rotation_x(&dt->view);
		*point = mat_point_mul(dt->view.rotation, *point);
		set_rotation_y(&dt->view);
		*point = mat_point_mul(dt->view.rotation, *point);
		set_rotation_z(&dt->view);
		*point = mat_point_mul(dt->view.rotation, *point);
		i++;
	}
}

static void	centralize(t_data *dt)
{
	int			i;
	int			map_w;
	int			map_h;
	t_limits	lim;
	t_point		offset;

	lim = dt->view.limits;
	map_w = lim.x_max - lim.x_min;
	map_h = lim.y_max - lim.y_min;
	offset.x = (WIN_WIDTH - map_w) / 2 - lim.x_min;
	offset.y = (WIN_HEIGHT - map_h) / 2 - lim.y_min;
	i = 0;
	while (i < dt->map->size)
	{
		dt->map->p_arr[i].x += 	offset.x;
		dt->map->p_arr[i].y += 	offset.y;
		i++;
	}
}

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

//testing
static void	print_limits(t_limits lim)
{
	ft_printf("WIN_WIDTH: %d\n", WIN_WIDTH);
	ft_printf("WIN_HEIGHT: %d\n", WIN_HEIGHT);
	ft_printf("x_max: %d\nx_min: %d\n", lim.x_max, lim.x_min);
	ft_printf("y_max: %d\ny_min: %d\n", lim.y_max, lim.y_min);
	ft_printf("z_max: %d\nz_min: %d\n", lim.z_max, lim.z_min);
}

void	render_map(t_data *dt)
{
	int		i;
	t_point	point;

	project_points(dt);
	set_limits(dt);
	centralize(dt);
	set_limits(dt);
	print_limits(dt->view.limits);
	i = 0;
	while (i < dt->map->size)
	{
		point = dt->map->p_arr[i];
		ft_printf("point %d:\nx -> %d\ny -> %d\nz -> %d\n\n", i, point.x, point.y, point.z);
		pixel_put(dt, point.x, point.y, point.color);
		i++;
	}
	mlx_put_image_to_window(dt->mlx, dt->mlx_win, dt->mlx_img, 0, 0);
}
