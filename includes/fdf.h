/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/25 16:17:32 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>

# define INVALID_INPUT_MSG "Error: invalid input.\n"
# define INVALID_EXTENSION_MSG "Error: invalid map extension.\n"

# define WIN_HEADER "FDF"
# define WIN_WIDTH 1366//1920
# define WIN_HEIGHT 768//1080

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	exit_with_cleanup(t_data *dt, int status);
void	init_win(t_data *data);
bool	validate_input(int argc, char **argv);

#endif