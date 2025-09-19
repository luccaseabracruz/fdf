/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:17:54 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/19 10:03:02 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdbool.h>

static bool	validate_format(char *map, char *format)
{
	while (*(++map))
	{
		map = ft_strnstr(map, format, ft_strlen(map));
		if (map && *(map + ft_strlen(format)) == 0)
			return (true);
		else if (!map)
			break ;
	}
	return (false);
}

bool	validate_input(int argc, char **argv)
{
	bool	res;

	res = true;
	if (argc != 2)
	{
		ft_putstr_fd(INVALID_INPUT_MSG, STDERR_FILENO);
		res = false;
	}
	else if (!validate_format(argv[1], ".fdf"))
	{
		ft_putstr_fd(INVALID_EXTENSION_MSG, STDERR_FILENO);
		res = false;
	}
	return (res);
}
