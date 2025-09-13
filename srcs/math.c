/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:22:05 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/13 16:36:33 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

double	degrees_to_radians(double degrees)
{
	double	res;

	res = degrees * (PI / 180);
	return (res);
}

t_point	mat_point_mul(double matrix[3][3], t_point point)
{
	double	cordinates[3];
	double	res[3];
	int		i;
	int		j;

	cordinates[0] = point.x;
	cordinates[1] = point.y;
	cordinates[2] = point.z;
	ft_bzero(&res, sizeof(res));
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res[i] += cordinates[j] * matrix[i][j];
			j++;
		}
		i++;
	}
	point.x = res[0];
	point.y = res[1];
	point.z = res[2];
	return (point);
}

int	absolute(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
