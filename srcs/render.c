/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:10:09 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/22 16:22:17 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	render_map(t_data *dt)
{
	project_points(dt);
	rotate(dt);
	centralize(dt);
	draw_lines(dt);
	mlx_put_image_to_window(dt->mlx, dt->mlx_win, dt->mlx_img, 0, 0);
}

void	rotate_render(t_data *dt, char axis, double rot_value)
{
	rot_value = degrees_to_radians(rot_value);
	if (axis == 'x')
		dt->view.rot_ang.x += rot_value;
	else if (axis == 'y')
		dt->view.rot_ang.y += rot_value;
	else if (axis == 'z')
		dt->view.rot_ang.z += rot_value;
	ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
	render_map(dt);
}

void	zoom_render(t_data *dt, double delta)
{
	dt->view.zoom += delta;
	ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
	render_map(dt);
}

void	pan_render(t_data *dt, char direction, int pan_value)
{
	if (direction == 'h')
		dt->view.pan_offset.x += pan_value;
	else if (direction == 'v')
		dt->view.pan_offset.y += pan_value;
	ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
	render_map(dt);
}