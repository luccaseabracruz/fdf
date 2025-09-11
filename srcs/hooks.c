/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:43:51 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/11 18:18:43 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>

// static int	key_hook(int keycode, t_data *vars)
// {
// 	ft_printf("Hello from key_hook!\n");
// 	return (0);
// }

static int	handle_keypress(int keycode, t_data *dt)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == XK_Escape)
		exit_with_cleanup(dt, EXIT_SUCCESS);
	if (keycode == XK_w)
		ft_printf(w)
	return (0);
}

void	hooks(t_data *dt)
{
	mlx_hook(dt->mlx_win, 2, 1L<<0, handle_keypress, dt);
}