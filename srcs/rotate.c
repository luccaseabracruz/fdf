/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:41:02 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/03 17:00:03 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_x(t_view *view, double angle)
{
	double	sine;
	double	cosine;

	sine = sin(angle);
	cosine = cos(angle);
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

void	rotate_y(t_view *view, double angle)
{
	double	sine;
	double	cosine;

	sine = sin(angle);
	cosine = cos(angle);
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

void	rotate_y(t_view *view, double angle)
{
	double	sine;
	double	cosine;

	sine = sin(angle);
	cosine = cos(angle);
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

void	rotate_z(t_view *view, double angle)
{
	double	sine;
	double	cosine;

	sine = sin(angle);
	cosine = cos(angle);
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
