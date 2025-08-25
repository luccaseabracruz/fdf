/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:23:28 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/25 15:20:11 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init_win(t_data *dt)
{
	dt->mlx = mlx_init();
	dt->mlx_win = mlx_new_window(dt->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_HEADER);
	dt->mlx_img = mlx_new_image(dt->mlx, WIN_WIDTH, WIN_HEIGHT);
	dt->addr = mlx_get_data_addr(
			dt->mlx_img, &dt->bits_per_pixel, &dt->line_length, &dt->endian);
}
