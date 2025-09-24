/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:55:20 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/23 15:35:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

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

static void	init_point(t_point *point, int x, int y, char *point_dt)
{
	char	**arg;

	arg = ft_split(point_dt, ',');
	ft_bzero(point, sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = ft_atoi(arg[0]);
	if (arg[1] && arg[1][0] == '0' && (arg[1][1] == 'x' || arg[1][1] == 'X'))
		point->color = ft_atoi_base(arg[1] + 2, HEX_BASE);
	else
		point->color = 0xFFFFFFFF;
	free_strarr(arg);
}

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
