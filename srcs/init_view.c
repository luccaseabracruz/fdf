/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:08:21 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/03 16:22:44 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_view(t_data *dt)
{
	t_view *view;

	view = &dt->view;
	ft_bzero(view);
	view->center.x = dt->map->rows / 2;
	view->center.y = dt->map->cols / 2;
	view->rot_ang.x = 
	view->rot_ang.y = 
}