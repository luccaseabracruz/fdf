/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:08:21 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 12:57:48 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

#include "fdf.h"
#include "libft.h"
#include <math.h>

/**
 * @brief Initializes the view structure with default parameters.
 *
 * Clears the view structure, sets default zoom, z-axis scaling, and grid
 * step size based on the window size and map dimensions. Sets initial
 * isometric rotation angles and initializes the rotation matrix as the
 * identity matrix.
 *
 * @param dt Pointer to the main data structure containing map and view info.
 *
 * Local variables:
 * - `view`: Pointer to the `t_view` structure inside `dt`.
 * 
 * External variables:
 * - `zoom`: Default zoom factor set to 1.
 * - `z_scaler`: Vertical scaling factor for the map (Z_SCALER).
 * - `grid_step`: Step size for the map grid, scaled to fit window.
 * - `rot_ang`: Initial rotation angles in radians for x, y, z axes.
 * - `rotation`: 3x3 rotation matrix initialized as identity.
 */
void	init_view(t_data *dt)
{
	t_view	*view;

	view = &dt->view;
	ft_bzero(view, sizeof(t_view));
	view->zoom = 1;
	view->z_scaler = Z_SCALER;
	view->grid_step = fmin(
			WIN_W / (double)dt->map->cols,
			WIN_H / (double)dt->map->rows
			) * MAP_FILL;
	view->rot_ang.x = degrees_to_radians(ISO_INIT_ANG_X);
	view->rot_ang.y = degrees_to_radians(ISO_INIT_ANG_Y);
	view->rot_ang.z = degrees_to_radians(ISO_INIT_ANG_Z);
	view->rotation[0][0] = 1.0;
	view->rotation[1][1] = 1.0;
	view->rotation[2][2] = 1.0;
}
