/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:13:34 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/03 15:42:37 by lseabra-         ###   ########.fr       */
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
# ifndef WIN_WIDTH
// #  define WIN_WIDTH 1366
#  define WIN_WIDTH 1920
# endif
# ifndef WIN_HEIGHT
// #  define WIN_HEIGHT 768
#  define WIN_HEIGHT 1080
# endif
# define FILL 0.7f
# define PI 3.14159265358979323846
# define ISO_SLOPE 30 * PI / 180
# define HEX_BASE "0123456789ABCDEF"


// FUNCTION DECLARATIONS
void	free_strarr(char **arr, int position);
void	free_nullstrarr(char **arr);
void	exit_with_cleanup(t_data *dt, int status);
void	perror_exit_cleanup(t_data *dt, char *msg, int status);
void	set_limits(t_data *dt);
void	init_map(t_data *dt, char **argv);
void	init_win(t_data *data);
void	render(t_data *dt);
bool	validate_input(int argc, char **argv);

#endif