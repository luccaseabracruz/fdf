/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:08:21 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/04 19:43:13 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

void	init_view(t_data *dt)
{
	t_view *view;

	view = &dt->view;
	ft_bzero(view, sizeof(t_view));
	view->center.x = dt->map->rows / 2;
	view->center.y = dt->map->cols / 2;
	view->rot_ang.x = ISO_INIT_ANG_X * (PI / 180);
	view->rot_ang.y = ISO_INIT_ANG_Y * (PI / 180);
	view->grid_step = WIN_WIDTH /dt->map->rows * MAP_FILL / 2;
	view->rotation[0][0] = 1.0;
	view->rotation[1][1] = 1.0;
	view->rotation[2][2] = 1.0;
}
