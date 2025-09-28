/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:41:02 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/28 15:53:26 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

/**
 * @file rotate.c
 * @brief Handles 3D rotation of projected map points.
 *
 * This file provides functionality to rotate map points around the X, Y,
 * and Z axes. The rotation is applied to each projected point in sequence,
 * ensuring correct visualization from the specified view angles.
 */

/**
 * @brief Builds the rotation matrix for the X axis.
 *
 * @param view Pointer to the view structure containing rotation angles
 *             and transformation matrix.
 */
static void	set_rotation_x(t_view *view)
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

/**
 * @brief Builds the rotation matrix for the Y axis.
 *
 * @param view Pointer to the view structure containing rotation angles
 *             and transformation matrix.
 */
static void	set_rotation_y(t_view *view)
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

/**
 * @brief Builds the rotation matrix for the Z axis.
 *
 * @param view Pointer to the view structure containing rotation angles
 *             and transformation matrix.
 */
static void	set_rotation_z(t_view *view)
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

/**
 * @brief Rotates all projected points around X, Y, and Z axes.
 *
 * For each projected point, its coordinates are shifted to the center,
 * rotated around the three axes, and then shifted back. The resulting
 * transformation ensures the map is rotated according to the current
 * view angles.
 *
 * @param dt Pointer to the main data structure containing map and view data.
 *
 * Local variables:
 * - t_point *proj → pointer to the current projected point.
 */
void	rotate(t_data *dt)
{
	int		i;
	t_point	*proj;

	i = 0;
	set_limits(dt);
	while (i < dt->map->size)
	{
		proj = &dt->map->proj_arr[i];
		proj->x -= dt->view.center.x;
		proj->y -= dt->view.center.y;
		set_rotation_x(&dt->view);
		*proj = mat_point_mul(dt->view.rotation, *proj);
		set_rotation_y(&dt->view);
		*proj = mat_point_mul(dt->view.rotation, *proj);
		set_rotation_z(&dt->view);
		*proj = mat_point_mul(dt->view.rotation, *proj);
		proj->x += dt->view.center.x;
		proj->y += dt->view.center.y;
		i++;
	}
}
