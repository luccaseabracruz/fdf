/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:43:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/18 17:03:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

static void	rotate_render(t_data *dt, char axis, double rot_value)
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

static int	handle_destroy(t_data *dt)
{
	exit_with_cleanup(dt, EXIT_SUCCESS);
	return (0);
}

#include <stdio.h>
static int	handle_key_press(int keycode, t_data *dt)
{
	if (keycode == XK_Escape)
		exit_with_cleanup(dt, EXIT_SUCCESS);
	else if (keycode == XK_w)
		rotate_render(dt, 'x', ROT_DEGREES);
	else if (keycode == XK_s)
		rotate_render(dt, 'x', -ROT_DEGREES);
	else if (keycode == XK_a)
		rotate_render(dt, 'y', ROT_DEGREES);
	else if (keycode == XK_d)
		rotate_render(dt, 'y', -ROT_DEGREES);
	else if (keycode == XK_q)
		rotate_render(dt, 'z', ROT_DEGREES);
	else if (keycode == XK_e)
		rotate_render(dt, 'z', -ROT_DEGREES);
	if (keycode == XK_equal && dt->view.zoom + ZOOM_SPEED < 0.999)
	{
		dt->view.zoom += ZOOM_SPEED;
		printf("zoom: %.2f\n", dt->view.zoom);
		ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
		render_map(dt);
	}
	if (keycode == XK_minus && dt->view.zoom - ZOOM_SPEED > 0.001)
	{
		dt->view.zoom -= ZOOM_SPEED;
		printf("zoom: %.2f\n", dt->view.zoom);
		ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
		render_map(dt);
	}
	return (0);
}

void	hooks(t_data *dt)
{
	mlx_hook(dt->mlx_win, 17, 0, handle_destroy, dt);
	mlx_key_hook(dt->mlx_win, handle_key_press, dt);
	// mlx_mouse_hook(dt->mlx_win, handle_mouse, dt);
}
