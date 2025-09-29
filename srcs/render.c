/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:10:09 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/28 15:49:22 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

/**
 * @brief Renders the map by projecting, transforming, and drawing points.
 *
 * Applies projection, rotation, and centralization to the map points, then
 * draws lines connecting them. Finally, displays the rendered image in the
 * MLX window.
 *
 * @param dt Pointer to the main data structure containing map and view info.
 */
void	render(t_data *dt)
{
	project_points(dt);
	rotate(dt);
	centralize(dt);
	draw_lines(dt);
	mlx_put_image_to_window(dt->mlx, dt->mlx_win, dt->mlx_img, 0, 0);
}
