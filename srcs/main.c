/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:51:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/27 18:34:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

static void	my_mlx_pixel_put(t_data *dt, int x, int y, int color)
{
	char	*dst;

	dst = dt->addr + (y * dt->line_length + x * (dt->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	dt;

	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	ft_bzero(&dt, sizeof(t_data));
	init_win(&dt);
	init_map(&dt, argv);
	my_mlx_pixel_put(&dt, 0, 0, 0x00FF0000);
	mlx_put_image_to_window(dt.mlx, dt.mlx_win, dt.mlx_img, 0, 0);
	mlx_loop(dt.mlx);
}
