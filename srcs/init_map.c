/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:55:20 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/03 13:22:13 by lseabra-         ###   ########.fr       */
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
		perror_exit_cleanup(dt, filename, EXIT_FAILURE);
	line = get_next_line(fd);
	row = ft_split(line, ' ');
	while (row[map->cols] && (row[map->cols][0] < 9 || row[map->cols][0] > 13))
		map->cols++;
	free_nullstrarr(row);
	while (line)
	{
		map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->size = map->cols * dt->map->rows;
}

static t_point	new_point(int x, int y, char *point_dt)
{
	t_point	point;
	char	**arg;

	arg = ft_split(point_dt, ',');
	ft_bzero(&point, sizeof(t_point));
	point.x = x;
	point.y = y;
	point.z = ft_atoi(arg[0]);
	if (arg[1] && arg[1][0] == '0' && (arg[1][1] == 'x' || arg[1][1] == 'X'))
		point.color = ft_atoi_base(arg[1] + 2, HEX_BASE);
	else
		point.color = 0xFFFFFFFF;
	free(arg);
	return (point);
}

static void	parse_map(t_data *dt, int map_fd)
{
	char	*line;
	char	**row;
	int		x;
	int		y;
	t_map	*map;

	map = dt->map;
	line = get_next_line(map_fd);
	y = 0;
	while (line)
	{
		row = ft_split(line, ' ');
		x = 0;
		while (x < map->cols)
		{
			map->p_arr[map->cols * y + x] = new_point(x, y, row[x]);
			x++;
		}
		free_nullstrarr(row);
		free(line);
		line = get_next_line(map_fd);
		y++;
	}
}

// static void	apply_iso(t_data *dt)
// {
// 	int		map_width;
// 	int		map_height;
// 	int		i;
// 	t_point	*point;

// 	map_width = dt->limits.x_max - dt->limits.x_min;
// 	map_height = dt->limits.y_max - dt->limits.y_min;
// 	dt->x_offset = (WIN_WIDTH * FILL - (map_width)) / 2 - dt->limits.x_min;
// 	dt->y_offset = (WIN_HEIGHT * FILL - (map_height)) / 2 - dt->limits.y_min;
// 	dt->map->scale = (float)fmin(WIN_WIDTH / (double)dt->map->cols,
// 	WIN_HEIGHT / (double)dt->map->rows) * FILL / 2.0f;
// 	i = 0;
// 	while (i < dt->map->point_count)
// 	{
// 		point = &dt->map->points[i];
// 		point->x_iso = (point->x - point->y) * cos(ISO_SLOPE) * dt->map->scale;
// 		point->x_iso += dt->x_offset;
// 		point->y_iso = (point->x + point->y) * sin(ISO_SLOPE) * dt->map->scale;
// 		point->y_iso += dt->y_offset;
// 		i++;
// 	}
// }

void	init_map(t_data *dt, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		perror_exit_cleanup(dt, argv[1], EXIT_FAILURE);
	dt->map = ft_calloc(1, sizeof(t_map));
	if (!dt->map)
	{
		close(fd);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	set_dimensions(dt, argv[1]);
	dt->map->p_arr = ft_calloc(dt->map->size, sizeof(t_point));
	if (!dt->map->p_arr)
	{
		close(fd);
		exit_with_cleanup(dt, EXIT_FAILURE);
	}
	parse_map(dt, fd);
	close(fd);
	set_limits(dt);
	apply_iso(dt);
}
