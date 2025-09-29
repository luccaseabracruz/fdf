/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:55:20 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 12:50:46 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

/**
 * @brief Sets the dimensions of the map (rows and columns) and total size.
 *
 * Opens the file and reads its lines to determine the number of rows and
 * columns. Columns are determined from the first line, ignoring whitespace
 * characters with ASCII between 9 and 13. Rows are counted line by line
 * until EOF.
 *
 * @param dt       Pointer to the main data structure containing the map.
 * @param filename Path to the map file.
 *
 * Local variables:
 * - `line`: Stores each line read from the file.
 * - `row`: Array of strings from splitting `line` by spaces.
 * - `fd`: File descriptor for the map file.
 * - `map`: Pointer to the map structure in `dt`.
 */
static void	set_dimensions(t_data *dt, char *filename)
{
	char	*line;
	char	**row;
	int		fd;
	t_map	*map;

	map = dt->map;
	fd = open(filename, O_RDONLY);
	if (fd < 3)
	{
		perror(filename);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	line = get_next_line(fd);
	row = ft_split(line, ' ');
	while (row[map->cols] && (row[map->cols][0] < 9 || row[map->cols][0] > 13))
		map->cols++;
	free_strarr(row);
	while (line)
	{
		map->rows++;
		free_and_null((void **)&line);
		line = get_next_line(fd);
	}
	close(fd);
	map->size = map->cols * dt->map->rows;
}

/**
 * @brief Initializes a single point of the map.
 *
 * Splits a string containing z-coordinate and optional color, converts
 * them, and assigns values to the point structure. Default color is white.
 *
 * @param point    Pointer to the point to initialize.
 * @param x        X-coordinate of the point.
 * @param y        Y-coordinate of the point.
 * @param point_dt String containing the point z(height) and color.
 *
 * Local variables:
 * - `arg`: Array from splitting the point string by ','.
 * - `i`: Index used for iterating over hex color string.
 */
static void	init_point(t_point *point, int x, int y, char *point_dt)
{
	char	**arg;
	int		i;

	arg = ft_split(point_dt, ',');
	ft_bzero(point, sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = ft_atoi(arg[0]);
	if (arg[1] && arg[1][0] == '0' && (arg[1][1] == 'x' || arg[1][1] == 'X'))
	{
		i = 2;
		while (arg[1][i])
		{
			arg[1][i] = ft_toupper(arg[1][i]);
			i++;
		}
		point->color = ft_atoi_base(arg[1] + 2, HEX_BASE);
	}
	else
		point->color = 0xFFFFFFFF;
	free_strarr(arg);
}

/**
 * @brief Parses the map file and fills the point array.
 *
 * Reads each line from the map file, splits it into columns, validates
 * the row length, and initializes the points in `p_arr`(original points array).
 *
 * @param dt      Pointer to the main data structure containing the map.
 * @param map_fd  File descriptor of the map file.
 *
 * Local variables:
 * - `line`: Current line read from the file.
 * - `row`: Array of strings obtained from splitting the line.
 * - `x`: Column index.
 * - `y`: Row index.
 */
static void	parse_map(t_data *dt, int map_fd)
{
	char	*line;
	char	**row;
	int		x;
	int		y;

	line = get_next_line(map_fd);
	y = 0;
	while (line)
	{
		row = ft_split(line, ' ');
		if (!validate_row(dt->map->cols, row))
		{
			close(map_fd);
			free_strarr(row);
			free_and_null((void **)&line);
			exit_with_cleanup(dt, EXIT_FAILURE);
		}
		x = -1;
		while (++x < dt->map->cols)
			init_point(&dt->map->p_arr[dt->map->cols * y + x], x, y, row[x]);
		free_strarr(row);
		free_and_null((void **)&line);
		line = get_next_line(map_fd);
		y++;
	}
}

/**
 * @brief Allocates memory for the point arrays in the map.
 *
 * Allocates `p_arr` for original points and `proj_arr` for projected
 * points. Exits with cleanup if allocation fails.
 *
 * @param dt Pointer to the main data structure containing the map.
 * @param fd File descriptor of the map file (closed on failure).
 */
static void	alloc_points(t_data *dt, int fd)
{
	dt->map->p_arr = ft_calloc(dt->map->size, sizeof(t_point));
	if (!dt->map->p_arr)
	{
		close(fd);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	dt->map->proj_arr = ft_calloc(dt->map->size, sizeof(t_point));
	if (!dt->map->proj_arr)
	{
		close(fd);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
}

/**
 * @brief Initializes the map structure and loads points from the file.
 *
 * Opens the file, allocates the map structure, sets dimensions, allocates
 * point arrays, parses the map, and closes the file.
 *
 * @param dt   Pointer to the main data structure.
 * @param argv Command-line arguments (argv[1] = map file path).
 *
 * Local variables:
 * - `fd`: File descriptor for the map file.
 */
void	init_map(t_data *dt, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	dt->map = ft_calloc(1, sizeof(t_map));
	if (!dt->map)
	{
		close(fd);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	set_dimensions(dt, argv[1]);
	alloc_points(dt, fd);
	parse_map(dt, fd);
	close(fd);
}
