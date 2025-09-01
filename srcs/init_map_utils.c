/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:57:45 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/31 17:55:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_limits(t_limits *lim)
{
	lim->x_min = WIN_WIDTH;
	lim->x_max = -WIN_WIDTH;
	lim->y_min = WIN_HEIGHT;
	lim->y_max = -WIN_HEIGHT;
	lim->z_min = WIN_HEIGHT;
	lim->z_max = -WIN_HEIGHT;
}

void	set_limits(t_data *dt)
{
	int		i;

	init_limits(&dt->limits);
	i = 0;
	while (i < dt->map->point_count)
	{
		if (dt->limits.x_min > dt->map->points[i].x)
			dt->limits.x_min = dt->map->points[i].x;
		if (dt->limits.x_max < dt->map->points[i].x)
			dt->limits.x_max = dt->map->points[i].x;
		if (dt->limits.y_min > dt->map->points[i].y)
			dt->limits.y_min = dt->map->points[i].y;
		if (dt->limits.y_max < dt->map->points[i].y)
			dt->limits.y_max= dt->map->points[i].y;
		if (dt->limits.z_min > dt->map->points[i].z)
			dt->limits.z_min = dt->map->points[i].z;
		if (dt->limits.z_max < dt->map->points[i].z)
			dt->limits.z_max = dt->map->points[i].z;
		i++;
	}
}
