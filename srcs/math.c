/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:22:05 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 15:02:15 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/**
 * @brief Convert degrees to radians.
 *
 * Multiplies the degree value by PI/180 to get the corresponding radian value.
 *
 * @param degrees Angle in degrees.
 *
 * Local variables:
 * - `res`: Resulting angle in radians.
 *
 * @return Angle in radians as double.
 */
double	degrees_to_radians(double degrees)
{
	double	res;

	res = degrees * (PI / 180);
	return (res);
}

/**
 * @brief Multiply a 3x3 matrix with a 3D point.
 *
 * Applies matrix multiplication to transform a 3D point using the given matrix.
 *
 * @param matrix 3x3 transformation matrix.
 * @param point  3D point to transform.
 *
 * Local variables:
 * - `cordinates`: Array storing the point coordinates.
 * - `res`: Array storing the resulting coordinates after multiplication.
 * - `i`, `j`: Loop counters.
 *
 * @return Transformed 3D point.
 */
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

/**
 * @brief Get the absolute value of an integer.
 *
 * Returns the non-negative value of the given integer.
 *
 * @param num Integer to process.
 *
 * @return Absolute value of the input integer.
 */
int	absolute(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
