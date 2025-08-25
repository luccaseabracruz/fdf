/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:06:22 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/25 16:19:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

static void	cleanup_data(t_data *dt)
{
	if (dt->mlx_img)
	{
		mlx_destroy_image(dt->mlx, dt->mlx_img);
		dt->mlx_img = NULL;
	}
	if (dt->mlx_win)
	{
		mlx_destroy_window(dt->mlx, dt->mlx_win);
		dt->mlx_win = NULL;
	}
	if (dt->mlx)
	{
		mlx_destroy_display(dt->mlx);
		dt->mlx = NULL;
	}
}

void	exit_with_cleanup(t_data *dt, int status)
{
	cleanup_data(dt);
	exit(status);
}
