/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/03 17:00:12 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_point;

typedef struct s_map
{
	int		cols;
	int		rows;
	t_point	*p_arr;
	int		size;
}			t_map;

// typedef struct s_limits
// {
// 	int	x_min;
// 	int	x_max;
// 	int	y_min;
// 	int	y_max;
// 	int	z_min;
// 	int	z_max;
// }			t_limits;

typedef struct s_axis
{
	double	x;
	double	y;
	double	z;
}			t_axis;

typedef struct s_view
{
	t_axis		center;
	t_axis		rot_ang;
	float		grid_step;
	double		rotation[3][3];
}			t_view;


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
}			t_data;

#endif