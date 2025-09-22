/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:59:31 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/22 15:46:41 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

void	set_limits(t_data *dt)
{
	int			i;
	t_limits	*lim;

	lim = &dt->view.limits;
	lim->x_min = INT_MAX;
	lim->x_max = INT_MIN;
	lim->y_min = INT_MAX;
	lim->y_max = INT_MIN;
	i = 0;
	while (i < dt->map->size)
	{
		if (lim->x_min > dt->map->proj_arr[i].x)
			lim->x_min = dt->map->proj_arr[i].x;
		if (lim->x_max < dt->map->proj_arr[i].x)
			lim->x_max = dt->map->proj_arr[i].x;
		if (lim->y_min > dt->map->proj_arr[i].y)
			lim->y_min = dt->map->proj_arr[i].y;
		if (lim->y_max < dt->map->proj_arr[i].y)
			lim->y_max = dt->map->proj_arr[i].y;
		i++;
	}
}
