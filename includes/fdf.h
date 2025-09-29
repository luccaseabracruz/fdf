/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/29 11:20:57 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//#============================================================================#
//#                                INCLUDES                                    #
//#============================================================================#
# include "types.h"
# include <stdbool.h>

//#============================================================================#
//#                                 MACROS                                     #
//#============================================================================#
# define FDF_EXT ".fdf"
# define INVALID_INPUT_MSG "Error: invalid input.\n"
# define INVALID_EXT_MSG "Error: invalid map extension.\n"
# define DIFF_ROW_SIZE_MSG "Error: diferent row size detected.\n"
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
# define ROT_DEGREES 1.0
# define ZOOM_STEP 0.05f
# define PAN_STEP 10
# define Z_SCALER 0.5f
# define Z_SCALER_STEP 0.02f
# define MAP_FILL 0.5f
# define PI 3.14159265358979323846
# define HEX_BASE "0123456789ABCDEF"

//#============================================================================#
//#                           FUNCTION PROTOTYPES                              #
//#============================================================================#
// srcs/
void	bresenham_line(t_data *dt, t_point p1, t_point p2);
void	free_and_null(void **ptr);
void	free_strarr(char **arr);
void	exit_with_cleanup(t_data *dt, int status);
int		color_between(t_bresenham b_dt, float ratio);
int		handle_destroy(t_data *dt);
void	hooks(t_data *dt);
void	init_map(t_data *dt, char **argv);
void	init_view(t_data *dt);
void	init_win(t_data *data);
double	degrees_to_radians(double degrees);
t_point	mat_point_mul(double matrix[3][3], t_point point);
int		absolute(int num);
void	project_points(t_data *dt);
void	centralize(t_data *dt);
void	draw_lines(t_data *dt);
void	render(t_data *dt);
void	rotate(t_data *dt);
void	set_limits(t_data *dt);
bool	validate_input(int argc, char **argv);
bool	validate_row(int row_size, char **row);

// srcs_bonus/
void	hooks_bonus(t_data *dt);
void	rotate_render(t_data *dt, char axis, double rot_value);
void	zoom_render(t_data *dt, double delta);
void	pan_render(t_data *dt, char direction, int pan_value);
void	change_proj_render(t_data *dt, char projection);
void	change_zscale_render(t_data *dt, double step);

#endif