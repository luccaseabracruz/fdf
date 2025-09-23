/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:43:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/23 11:38:35 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

static int	handle_destroy(t_data *dt)
{
	exit_with_cleanup(dt, EXIT_SUCCESS);
	return (0);
}

static int	handle_key_arrows(int keycode, t_data *dt)
{
	if (keycode == XK_Up)
		pan_render(dt, 'v', -PAN_STEP);
	else if (keycode == XK_Down)
		pan_render(dt, 'v', PAN_STEP);
	else if (keycode == XK_Right)
		pan_render(dt, 'h', PAN_STEP);
	else if (keycode == XK_Left)
		pan_render(dt, 'h', -PAN_STEP);
	return (0);
}

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
	else if (keycode == XK_equal)
		zoom_render(dt, ZOOM_STEP);
	else if (keycode == XK_minus && dt->view.zoom - ZOOM_STEP > 0.001)
		zoom_render(dt, -ZOOM_STEP);
	handle_key_arrows (keycode, dt);
	return (0);
}

void	hooks(t_data *dt)
{
	mlx_hook(dt->mlx_win, 17, 0, handle_destroy, dt);
	mlx_key_hook(dt->mlx_win, handle_key_press, dt);
}
