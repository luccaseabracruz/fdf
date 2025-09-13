/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:41:02 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/13 16:36:55 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	reset_rotation(t_view *view)
{
	view->rotation[0][0] = 1;
	view->rotation[0][1] = 0;
	view->rotation[0][2] = 0;
	view->rotation[1][0] = 0;
	view->rotation[1][1] = 1;
	view->rotation[1][2] = 0;
	view->rotation[2][0] = 0;
	view->rotation[2][1] = 0;
	view->rotation[2][2] = 1;
}

void	set_rotation_x(t_view *view)
{
	double	sine;
	double	cosine;

	sine = sin(view->rot_ang.x);
	cosine = cos(view->rot_ang.x);
	view->rotation[0][0] = 1;
	view->rotation[0][1] = 0;
	view->rotation[0][2] = 0;
	view->rotation[1][0] = 0;
	view->rotation[1][1] = cosine;
	view->rotation[1][2] = -sine;
	view->rotation[2][0] = 0;
	view->rotation[2][1] = sine;
	view->rotation[2][2] = cosine;
}

void	set_rotation_y(t_view *view)
{
	double	sine;
	double	cosine;

	sine = sin(view->rot_ang.y);
	cosine = cos(view->rot_ang.y);
	view->rotation[0][0] = cosine;
	view->rotation[0][1] = 0;
	view->rotation[0][2] = sine;
	view->rotation[1][0] = 0;
	view->rotation[1][1] = 1;
	view->rotation[1][2] = 0;
	view->rotation[2][0] = -sine;
	view->rotation[2][1] = 0;
	view->rotation[2][2] = cosine;
}

void	set_rotation_z(t_view *view)
{
	double	sine;
	double	cosine;

	sine = sin(view->rot_ang.z);
	cosine = cos(view->rot_ang.z);
	view->rotation[0][0] = cosine;
	view->rotation[0][1] = -sine;
	view->rotation[0][2] = 0;
	view->rotation[1][0] = sine;
	view->rotation[1][1] = cosine;
	view->rotation[1][2] = 0;
	view->rotation[2][0] = 0;
	view->rotation[2][1] = 0;
	view->rotation[2][2] = 1;
}
