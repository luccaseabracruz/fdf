/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:43:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/24 18:43:00 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

int	handle_destroy(t_data *dt)
{
	exit_with_cleanup(dt, EXIT_SUCCESS);
	return (0);
}

static int	handle_key_press(int keycode, t_data *dt)
{
	if (keycode == XK_Escape)
		exit_with_cleanup(dt, EXIT_SUCCESS);
	return (0);
}

void	hooks(t_data *dt)
{
	mlx_hook(dt->mlx_win, 17, 0, handle_destroy, dt);
	mlx_hook(dt->mlx_win, 2, (1L << 0), handle_key_press, dt);
}
