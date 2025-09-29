/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/29 11:16:57 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

//#============================================================================#
//#                                INCLUDES                                    #
//#============================================================================#
# include <stdbool.h>

//#============================================================================#
//#                                 TYPES                                      #
//#============================================================================#

/**
 * @brief Represents a 3D point in space with an optional color.
 */
typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

/**
 * @brief Represents the map/grid data for the FDF program.
 */
typedef struct s_map
{
	int		cols;
	int		rows;
	t_point	*p_arr;
	t_point	*proj_arr;
	int		size;
}	t_map;

/**
 * @brief Stores minimum and maximum coordinates for the rendered points.
 */
typedef struct s_limits
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}	t_limits;

/**
 * @brief Represents rotation along X, Y, Z axes.
 */
typedef struct s_axis
{
	double	x;
	double	y;
	double	z;
}	t_axis;

/**
 * @brief Stores the actual drawing parameters for rendering.
 */
typedef struct s_view
{
	t_axis		rot_ang;
	double		grid_step;
	double		z_scaler;
	double		rotation[3][3];
	t_limits	limits;
	t_point		center;
	t_point		pan_offset;
	double		zoom;
}	t_view;

/**
 * @struct s_data
 * @brief Central context structure for the FDF program.
 *
 * This structure holds all the essential state needed during runtime:
 *  - Pointers to MiniLibX instances for window and image management
 *  - Image buffer address and metadata (bits per pixel, line length, endian)
 *  - A pointer to the loaded map structure with geometry data
 *  - The active view configuration (rotation, scaling, panning, zoom, limits)
 *
 * It acts as the main "handle" passed across the program, ensuring that
 * rendering, transformations, and event handling all operate on a consistent
 * shared state.
 */
typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_view		view;
}	t_data;

/**
 * @brief Stores parameters for Bresenham line algorithm.
 */
typedef struct s_bresenham
{
	t_point	p1;
	t_point	p2;
	int		dx;
	int		dy;
	int		xstep;
	int		ystep;
}	t_bresenham;

/**
 * @brief Stores ARGB color components separately.
 */
typedef struct s_argb
{
	int	alpha;
	int	red;
	int	green;
	int	blue;
}	t_argb;

#endif