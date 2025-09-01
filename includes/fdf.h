/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/31 17:58:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>

# define INVALID_INPUT_MSG "Error: invalid input.\n"
# define INVALID_EXTENSION_MSG "Error: invalid map extension.\n"

# define WIN_HEADER "FDF"
# ifndef WIN_WIDTH
#  define WIN_WIDTH 1366
// #  define WIN_WIDTH 1920
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 768
// #  define WIN_HEIGHT 1080
# endif
# define FILL 0.7f
# define PI 3.14159265358979323846
# define ISO_SLOPE 30 * PI / 180
# define HEX_BASE "0123456789ABCDEF"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	x_iso;
	int	y_iso;
	int	color;
}			t_point;

typedef struct s_map
{
	int		columns;
	int		rows;
	t_point	*points;
	int		point_count;
	float	scale;
}			t_map;

typedef struct s_limits
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
	int	z_min;
	int	z_max;
}			t_limits;

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
	t_limits	limits;
	int			x_offset;
	int			y_offset;
}			t_data;

void	free_strarr(char **arr, int position);
void	free_nullstrarr(char **arr);
void	exit_with_cleanup(t_data *dt, int status);
void	perror_exit_cleanup(t_data *dt, char *msg, int status);
void	set_limits(t_data *dt);
void	init_map(t_data *dt, char **argv);
void	init_win(t_data *data);
void	print_map(t_data *dt);
bool	validate_input(int argc, char **argv);

#endif