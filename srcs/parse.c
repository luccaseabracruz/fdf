/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:49:43 by lseabra-          #+#    #+#             */
/*   Updated: 2025/08/23 12:48:59 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdbool.h>

bool	validate_format(char *map, char *format)
{
	while (*(++map))
	{
		map = ft_strnstr(map, format, ft_strlen(map));
		if(map && *(map + ft_strlen(format)) == 0)
			return (true);
		else if (!map)
			break ;
	}
	return (false);
}

// #include <stddef.h>
// int	main(int c, char **v)
// {
// 	if (c != 3)
// 		return (1);
// 	ft_printf("map: %s\nformat: %s\nis valid? %d\n", v[1], v[2], validate_format(v[1], v[2]));
// }