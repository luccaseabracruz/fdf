/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/24 19:58:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_map
{
	int		cols;
	int		rows;
	t_point	*p_arr;
	t_point	*proj_arr;
	int		size;
}	t_map;

typedef struct s_limits
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}	t_limits;

typedef struct s_axis
{
	double	x;
	double	y;
	double	z;
}	t_axis;

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

typedef struct s_bresenham
{
	t_point	p1;
	t_point	p2;
	int		dx;
	int		dy;
	int		xstep;
	int		ystep;
}	t_bresenham;

typedef struct s_argb
{
	int	alpha;
	int	red;
	int	green;
	int	blue;
}	t_argb;

#endif