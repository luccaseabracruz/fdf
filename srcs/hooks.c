/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:43:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 12:37:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

/**
 * @brief Handle window destroy event (clicking the close button).
 *
 * This function is triggered when the user closes the program window
 * using the window manager's close button (event code 17).
 *
 * @param dt Pointer to the program's main data structure.
 *
 * @return Always returns 0 (required by MiniLibX hook signature).
 */
int	handle_destroy(t_data *dt)
{
	exit_with_cleanup(dt, EXIT_SUCCESS);
	return (0);
}

/**
 * @brief Handle key press events.
 *
 * This function listens for key presses and executes actions based on
 * the pressed key event. Currently, it only handles the Escape key to 
 * quit the program.
 *
 * @param keycode Integer code of the pressed key (from X11/keysym.h).
 * @param dt      Pointer to the program's main data structure.
 *
 * @return Always returns 0 (required by MiniLibX hook signature).
 */
static int	handle_key_press(int keycode, t_data *dt)
{
	if (keycode == XK_Escape)
		exit_with_cleanup(dt, EXIT_SUCCESS);
	return (0);
}

/**
 * @brief Register window hooks for event handling.
 *
 * Sets up MiniLibX hooks to handle window close (destroy) and
 * key press events.
 *
 * @param dt Pointer to the program's main data structure.
 *
 * Events registered:
 * - Event 17 → Window close button → calls @ref handle_destroy.
 * - Event 2  → Key press → calls @ref handle_key_press.
 */
void	hooks(t_data *dt)
{
	mlx_hook(dt->mlx_win, 17, 0, handle_destroy, dt);
	mlx_hook(dt->mlx_win, 2, (1L << 0), handle_key_press, dt);
}
