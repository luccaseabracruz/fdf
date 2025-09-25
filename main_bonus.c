/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:51:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 10:50:40 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main_bonus.c
 * @brief Entry point of the bonus FdF program.
 *
 * This file initializes and runs the extended version of the FdF program,
 * including additional features such as enhanced controls and rendering options.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return EXIT_SUCCESS (0) on normal execution,
 *         EXIT_FAILURE (1) if the input is invalid.
 */
#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	dt;

	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	ft_bzero(&dt, sizeof(t_data));
	init_map(&dt, argv);
	init_win(&dt);
	init_view(&dt);
	render(&dt);
	hooks_bonus(&dt);
	mlx_loop(dt.mlx);
}
