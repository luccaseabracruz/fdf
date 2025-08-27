/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:55:20 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/27 22:05:02 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

void	set_dimensions(t_data *dt, char *file)
{
	char	*line;
	char	**row;
	int		width;
	int		map_fd;

	map_fd = open(file, O_RDONLY);
	if (map_fd < 0)
		perror_exit_cleanup(dt, file, EXIT_FAILURE);
	line = get_next_line(map_fd);
	row = ft_split(line, ' ');
	width = 0;
	while (row[width] && !(row[width][0] >= 9 && row[width][0] <= 13))
		width++;
	free_nullstrarr(row);
	dt->map->width = width;
	while (line)
	{
		dt->map->height++;
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	dt->map->point_count = dt->map->width * dt->map->height;
}

void	init_point(t_data *dt, int x, int y, char *value)
{
	t_point	*point;
	char	**arg;

	arg = ft_split(value, ',');
	point = &dt->map->points[(dt->map->width * y) + x];
	point->x = x;
	point->y = y;
	point->z = ft_atoi(arg[0]);
	if (arg[1] && arg[1][0] == '0' && (arg[1][1] == 'x' || arg[1][1] == 'X'))
		point->color = ft_atoi_base(arg[1] + 2, HEX_BASE);
	else
		point->color = 0x00FF0000;
	free(arg);
}

void	parse_map(t_data *dt, int map_fd)
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
		while (x < dt->map->width)
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
}
