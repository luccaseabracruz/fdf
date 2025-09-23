/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:17:54 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/23 11:45:58 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>

static bool	validate_extension(char *map, char *format)
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
	else if (!validate_extension(argv[1], FDF_EXT))
	{
		write(STDERR_FILENO, INVALID_EXT_MSG, ft_strlen(INVALID_EXT_MSG));
		res = false;
	}
	return (res);
}

bool	validate_row(int map_cols, char **row)
{
	bool	res;
	int		cols_size;

	res = true;
	cols_size = 0;
	while (row[cols_size] && (row[cols_size][0] < 9 || row[cols_size][0] > 13))
		cols_size++;
	if (cols_size != map_cols)
	{
		write(STDERR_FILENO, DIFF_ROW_SIZE_MSG, ft_strlen(DIFF_ROW_SIZE_MSG));
		res = false;
	}
	return (res);
}
