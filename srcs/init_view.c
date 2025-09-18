/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:08:21 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/18 15:27:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

static void	init_limits(t_limits *lim)
{
	lim->x_min = INT_MAX;
	lim->x_max = INT_MIN;
	lim->y_min = INT_MAX;
	lim->y_max = INT_MIN;
}

void	init_view(t_data *dt)
{
	t_view	*view;

	view = &dt->view;
	ft_bzero(view, sizeof(t_view));
	view->grid_step = fmin(
			WIN_WIDTH / (double)dt->map->cols,
			WIN_HEIGHT / (double)dt->map->rows
			) * MAP_FILL;
	view->rot_ang.x = degrees_to_radians(ISO_INIT_ANG_X);
	view->rot_ang.y = degrees_to_radians(ISO_INIT_ANG_Y);
	view->rot_ang.z = degrees_to_radians(ISO_INIT_ANG_Z);
	view->rotation[0][0] = 1.0;
	view->rotation[1][1] = 1.0;
	view->rotation[2][2] = 1.0;
	init_limits(&dt->view.limits);
}
