/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:51:01 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/23 13:09:11 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc !=2)
	{
		ft_putstr_fd("Error: invalid input.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (!validate_format(argv[1], ".fdf"))
	{
		ft_putstr_fd("Error: invalid map extension.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (0);
}
