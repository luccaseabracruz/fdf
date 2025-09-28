/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:17:54 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/28 16:00:02 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>

/**
 * @file validate.c
 * @brief Input and map validation utilities.
 *
 * Provides functions to validate program arguments, file extensions,
 * and consistency of map rows. Errors are reported to STDERR with
 * predefined messages.
 */

/**
 * @brief Checks if a given filename ends with the specified extension.
 *
 * Iterates over the filename string searching for the extension substring.
 * If found at the end of the string, the filename is considered valid.
 *
 * @param map    The filename string to validate.
 * @param format The required file extension (e.g., ".fdf").
 * @return true if the extension is valid, false otherwise.
 */
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

/**
 * @brief Validates program arguments and input file extension.
 *
 * Ensures that exactly one filename argument is passed and that the
 * filename has the correct extension. Prints error messages to STDERR
 * if validation fails.
 *
 * @param argc Number of command-line arguments.
 * @param argv Argument vector (expects argv[1] as the filename).
 * @return true if input is valid, false otherwise.
 *
 * Local variables:
 * - `res`: Boolean result flag.
 */
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

/**
 * @brief Validates the number of columns in a map row.
 *
 * Iterates through the row array counting valid entries (ignoring
 * whitespace and control characters). Ensures the row has the same
 * number of columns as defined in the map header.
 *
 * @param map_cols Expected number of columns in each row.
 * @param row      Array of strings representing one line of the map.
 *
 * Local variables:
 * - `res`: Boolean result flag.
 * - `cols_size`: Counter for the number of valid entries in the row.
 * 
 * @return true if the row size matches, false otherwise.
 */
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
