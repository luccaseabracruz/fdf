/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:51:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 10:49:49 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief Entry point of the mandatory FdF program.
 * Note: bonus features are compiled separately in @ref main_bonus.c.
 *
 * This function initializes the application by:
 * - Validating the program input.
 * - Initializing the map data.
 * - Creating the window and setting up the view.
 * - Rendering the initial frame.
 * - Registering hooks for user interaction.
 * - Starting the MLX event loop.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return EXIT_SUCCESS (0) on normal execution,
 *         EXIT_FAILURE (1) if the input is invalid.
 */
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
	hooks(&dt);
	mlx_loop(dt.mlx);
}
