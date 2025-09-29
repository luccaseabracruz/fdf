/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:23:28 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 14:56:16 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief Initialize the MLX window and image.
 *
 * Sets up the MLX instance, creates a window and an image, and retrieves the 
 * image data address along with its parameters. Exits the program with cleanup
 * if any initialization step fails.
 *
 * @param dt Pointer to a t_data structure where MLX pointers and image data
 *           parameters will be stored.
 */
void	init_win(t_data *dt)
{
	dt->mlx = mlx_init();
	if (!dt->mlx)
	{
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	dt->mlx_win = mlx_new_window(dt->mlx, WIN_W, WIN_H, WIN_HEADER);
	if (!dt->mlx_win)
	{
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	dt->mlx_img = mlx_new_image(dt->mlx, WIN_W, WIN_H);
	if (!dt->mlx_img)
	{
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	dt->addr = mlx_get_data_addr(
			dt->mlx_img, &dt->bits_per_pixel, &dt->line_length, &dt->endian);
}
