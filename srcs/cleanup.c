/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:06:22 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/18 14:30:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	free_nullstrarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	free_and_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

static void	exit_window(t_data *dt)
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
	exit_window(dt);
	free_and_null(dt->map->p_arr);
	free_and_null(dt->map->proj_arr);
	exit(status);
}
