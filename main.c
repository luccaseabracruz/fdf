/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:51:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/22 15:10:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_data	dt;

	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	ft_bzero(&dt, sizeof(t_data));
	init_win(&dt);
	init_map(&dt, argv);
	init_view(&dt);
	render_map(&dt);
	hooks(&dt);
	mlx_loop(dt.mlx);
}
