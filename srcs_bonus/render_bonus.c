/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:08:09 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/28 16:14:10 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/**
 * @file render_bonus.c
 * @brief Rendering helpers for bonus controls.
 *
 * Provides transformations that respond to user input: rotation, zoom, panning,
 * projection changes, and Z-scale adjustments. Each function clears the frame
 * buffer before re-rendering the scene.
 */

/**
 * @brief Rotates the map around the given axis and re-renders.
 *
 * @param dt        Pointer to main program data.
 * @param axis      Axis to rotate around ('x', 'y', 'z').
 * @param rot_value Rotation value in degrees.
 */
void	rotate_render(t_data *dt, char axis, double rot_value)
{
	rot_value = degrees_to_radians(rot_value);
	if (axis == 'x')
		dt->view.rot_ang.x += rot_value;
	else if (axis == 'y')
		dt->view.rot_ang.y += rot_value;
	else if (axis == 'z')
		dt->view.rot_ang.z += rot_value;
	ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
	render(dt);
}

/**
 * @brief Adjusts the zoom level and re-renders.
 *
 * @param dt    Pointer to main program data.
 * @param delta Increment to apply to zoom factor.
 */
void	zoom_render(t_data *dt, double delta)
{
	dt->view.zoom += delta;
	ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
	render(dt);
}

/**
 * @brief Applies panning (horizontal or vertical) and re-renders.
 *
 * - `'h'`: Horizontal direction.
 * - `'v'`: Vertical direction.
 * 
 * @param dt        Pointer to main program data.
 * @param direction Direction of pan ('h' or 'v'W).
 * @param pan_value Offset value to apply.
 */
void	pan_render(t_data *dt, char direction, int pan_value)
{
	if (direction == 'h')
		dt->view.pan_offset.x += pan_value;
	else if (direction == 'v')
		dt->view.pan_offset.y += pan_value;
	ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
	render(dt);
}

/**
 * @brief Switches between projection modes and re-renders.
 *
 * - `'i'`: Isometric projection (default).
 * - `'o'`: Orthographic projection.
 *
 * @param dt         Pointer to main program data.
 * @param projection Projection type ('i' or 'o').
 *
 * Local variables: None.
 */
void	change_proj_render(t_data *dt, char projection)
{
	if (projection == 'i')
	{
		dt->view.rot_ang.x = degrees_to_radians(ISO_INIT_ANG_X);
		dt->view.rot_ang.y = degrees_to_radians(ISO_INIT_ANG_Y);
		dt->view.rot_ang.z = degrees_to_radians(ISO_INIT_ANG_Z);
		ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
		render(dt);
	}
	else if (projection == 'o')
	{
		dt->view.rot_ang.x = 0;
		dt->view.rot_ang.y = 0;
		dt->view.rot_ang.z = 0;
		ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
		render(dt);
	}
}

/**
 * @brief Adjusts the Z-axis scaling factor and re-renders.
 *
 * @param dt   Pointer to main program data.
 * @param step Increment to apply to z_scaler.
 */
void	change_zscale_render(t_data *dt, double step)
{
	dt->view.z_scaler += step;
	ft_memset(dt->addr, 0, WIN_W * WIN_H * (dt->bits_per_pixel / 8));
	render(dt);
}
