/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/18 16:06:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "types.h"
# include <stdbool.h>

// MACROS
# define INVALID_INPUT_MSG "Error: invalid input.\n"
# define INVALID_EXTENSION_MSG "Error: invalid map extension.\n"
# define WIN_HEADER "FDF"
# ifndef WIN_W
// #  define WIN_W 1366
#  define WIN_W 1920
# endif
# ifndef WIN_H
// #  define WIN_H 650
#  define WIN_H 1080
# endif
# define ISO_INIT_ANG_X 45
# define ISO_INIT_ANG_Y 45
# define ISO_INIT_ANG_Z -30
# define ROT_DEGREES 2.0
# define ZOOM_SPEED 0.05
# define Z_SCALER 0.5
# define MAP_FILL 0.5f
# define PI 3.14159265358979323846
# define HEX_BASE "0123456789ABCDEF"

// FUNCTION DECLARATIONS
void	bresenham_line(t_data *dt, t_point p1, t_point p2);
void	free_nullstrarr(char **arr);
void	exit_with_cleanup(t_data *dt, int status);
void	hooks(t_data *dt);
void	init_map(t_data *dt, char **argv);
void	init_view(t_data *dt);
void	init_win(t_data *data);
double	degrees_to_radians(double degrees);
t_point	mat_point_mul(double matrix[3][3], t_point point);
int		absolute(int num);
void	render_map(t_data *dt);
void	reset_rotation(t_view *view);
void	set_rotation_x(t_view *view);
void	set_rotation_y(t_view *view);
void	set_rotation_z(t_view *view);
bool	validate_input(int argc, char **argv);

#endif