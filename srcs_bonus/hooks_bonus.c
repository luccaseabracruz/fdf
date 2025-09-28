/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:43:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/28 16:15:58 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
/**
 * @file hooks_bonus.c
 * @brief Bonus event handling (keyboard and window hooks).
 *
 * Provides key press handling for panning, rotating, zooming,
 * projection changes, Z-scaling, and window destruction.
 *
 * The bonus controls include:
 * - **Arrows** → Pan (horizontal/vertical).
 * - **W/S** → Rotate around X-axis.
 * - **A/D** → Rotate around Y-axis.
 * - **Q/E** → Rotate around Z-axis.
 * - **=/-** → Zoom in/out.
 * - **I/O** → Change projection.
 * - **Z/X** → Decrease/increase Z-scale.
 * - **ESC** → Exit program.
 */

/**
 * @brief Handles arrow key presses for panning.
 *
 * @param keycode Key symbol code (XK_Up, XK_Down, XK_Left, XK_Right).
 * @param dt      Pointer to main program data.
 */
static int	handle_arrow_keys_bonus(int keycode, t_data *dt)
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

/**
 * @brief Handles rotation key presses.
 *
 * @param keycode Key symbol code (XK_w, XK_s, XK_a, XK_d, XK_q, XK_e).
 * @param dt      Pointer to main program data.
 */
static int	handle_rot_keys_bonus(int keycode, t_data *dt)
{
	if (keycode == XK_w)
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
	return (0);
}

/**
 * @brief Main key press event dispatcher.
 *
 * Matches key presses against available controls and triggers
 * the appropriate render update (zoom, rotate, pan, projection
 * change, Z-scale change). Also handles program exit on ESC.
 *
 * @param keycode Key symbol code.
 * @param dt      Pointer to main program data.
 */
static int	handle_key_press_bonus(int keycode, t_data *dt)
{
	if (keycode == XK_Escape)
		exit_with_cleanup(dt, EXIT_SUCCESS);
	else if (keycode == XK_equal)
		zoom_render(dt, ZOOM_STEP);
	else if (keycode == XK_minus && dt->view.zoom - ZOOM_STEP > 0.001)
		zoom_render(dt, -ZOOM_STEP);
	else if (keycode == XK_i)
		change_proj_render(dt, 'i');
	else if (keycode == XK_o)
		change_proj_render(dt, 'o');
	else if (keycode == XK_z)
		change_zscale_render(dt, -Z_SCALER_STEP);
	else if (keycode == XK_x)
		change_zscale_render(dt, Z_SCALER_STEP);
	else
	{
		handle_rot_keys_bonus(keycode, dt);
		handle_arrow_keys_bonus(keycode, dt);
	}
	return (0);
}

/**
 * @brief Registers event hooks for bonus controls.
 *
 * Hooks the following events into the MiniLibX loop:
 * - Destroy notify (close window) → `handle_destroy()`.
 * - Key press events → `handle_key_press_bonus()`.
 *
 * @param dt Pointer to main program data.
 */
void	hooks_bonus(t_data *dt)
{
	mlx_hook(dt->mlx_win, 17, 0, handle_destroy, dt);
	mlx_hook(dt->mlx_win, 2, (1L << 0), handle_key_press_bonus, dt);
}
