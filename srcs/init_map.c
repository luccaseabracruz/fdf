/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:55:20 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/31 17:59:59 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

static void	set_dimensions(t_data *dt, char *file)
{
	char	*line;
	char	**row;
	int		columns;
	int		map_fd;

	map_fd = open(file, O_RDONLY);
	if (map_fd < 0)
		perror_exit_cleanup(dt, file, EXIT_FAILURE);
	line = get_next_line(map_fd);
	row = ft_split(line, ' ');
	columns = 0;
	while (row[columns] && !(row[columns][0] >= 9 && row[columns][0] <= 13))
		columns++;
	free_nullstrarr(row);
	dt->map->columns = columns;
	while (line)
	{
		dt->map->rows++;
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	dt->map->point_count = dt->map->columns * dt->map->rows;
	// dt->map->scale = (float)fmin(WIN_WIDTH / (double)columns,
	// 	WIN_HEIGHT / (double)dt->map->rows) * FILL / 2.0f;
}

static void	init_point(t_data *dt, int x, int y, char *value)
{
	t_point	*point;
	char	**arg;

	arg = ft_split(value, ',');
	point = &dt->map->points[(dt->map->columns * y) + x];
	point->x = x;
	point->y = y;
	point->z = ft_atoi(arg[0]);
	if (arg[1] && arg[1][0] == '0' && (arg[1][1] == 'x' || arg[1][1] == 'X'))
		point->color = ft_atoi_base(arg[1] + 2, HEX_BASE);
	else
		point->color = 0xFFFFFFFF;
	free(arg);
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
		x = 0;
		while (x < dt->map->columns)
		{
			init_point(dt, x, y, row[x]);
			x++;
		}
		free_nullstrarr(row);
		free(line);
		line = get_next_line(map_fd);
		y++;
	}
}

static void	apply_iso(t_data *dt)
{
	int		map_width;
	int		map_height;
	int		i;
	t_point	*point;

	map_width = dt->limits.x_max - dt->limits.x_min;
	map_height = dt->limits.y_max - dt->limits.y_min;
	dt->x_offset = (WIN_WIDTH * FILL - (map_width)) / 2 - dt->limits.x_min;
	dt->y_offset = (WIN_HEIGHT * FILL - (map_height)) / 2 - dt->limits.y_min;
	dt->map->scale = (float)fmin(WIN_WIDTH / (double)dt->map->columns,
	WIN_HEIGHT / (double)dt->map->rows) * FILL / 2.0f;
	i = 0;
	while (i < dt->map->point_count)
	{
		point = &dt->map->points[i];
		point->x_iso = (point->x - point->y) * cos(ISO_SLOPE) * dt->map->scale;
		point->x_iso += dt->x_offset;
		point->y_iso = (point->x + point->y) * sin(ISO_SLOPE) * dt->map->scale;
		point->y_iso += dt->y_offset;
		i++;
	}
}

void	init_map(t_data *dt, char **argv)
{
	int		map_fd;

	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
		perror_exit_cleanup(dt, argv[1], EXIT_FAILURE);
	dt->map = ft_calloc(1, sizeof(t_map));
	if (!dt->map)
	{
		close(map_fd);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	set_dimensions(dt, argv[1]);
	dt->map->points = ft_calloc(dt->map->point_count, sizeof(t_point));
	if (!dt->map->points)
	{
		close(map_fd);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	parse_map(dt, map_fd);
	close(map_fd);
	set_limits(dt);
	apply_iso(dt);
}
