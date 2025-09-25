/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_between.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:21:50 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/25 12:32:15 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Convert a packed integer color to ARGB components.
 *
 * Decomposes a 32-bit integer color value into its alpha, red,
 * green, and blue channels stored in a @ref t_argb struct.
 * 
 * Bit layout of the input integer:
 * 31 ------- 24 23 -------- 16 15 --------- 8 7 ---------- 0
 * |   ALPHA    |     RED      |    GREEN     |    BLUE     |
 *
 * @param color Integer color in ARGB format (0xAARRGGBB).
 *
 * Local variables:
 * - `argb`: Resulting structure containing the extracted channels.
 *
 * @return A @ref t_argb struct with separated channels.
 */
static t_argb	int_to_argb(int color)
{
	t_argb	argb;

	argb.alpha = color >> 24 & 0xFF;
	argb.red = color >> 16 & 0xFF;
	argb.green = color >> 8 & 0xFF;
	argb.blue = color & 0xFF;
	return (argb);
}

/**
 * @brief Convert ARGB components to a packed integer color.
 *
 * Combines alpha, red, green, and blue values into a single
 * 32-bit integer in the ARGB format.
 *
 * Bit layout of the output integer:
 * 31 ------- 24 23 -------- 16 15 --------- 8 7 ---------- 0
 * |   ALPHA    |     RED      |    GREEN     |    BLUE     |
 * 
 * @param argb ARGB components stored in a @ref t_argb struct.
 *
 * Local variables:
 * - `res`: Integer result after combining all channels.
 *
 * @return Integer color in ARGB format (0xAARRGGBB).
 */
static int	argb_to_int(t_argb argb)
{
	int	res;

	res = argb.alpha << 24;
	res += argb.red << 16;
	res += argb.green << 8;
	res += argb.blue;
	return (res);
}

/**
 * @brief Interpolate color between two points.
 *
 * Calculates a color value at a given position between two points
 * using linear interpolation of ARGB channels.
 *
 * @param b_dt   Bresenham line data containing two points with colors.
 * @param ratio  Interpolation factor (0.0 = p1, 1.0 = p2).
 *
 * Local variables:
 * - `p1`: ARGB color of the first point.
 * - `p2`: ARGB color of the second point.
 * - `res`: Resulting interpolated ARGB color.
 *
 * @return Integer color in ARGB format at the given ratio.
 */
int	color_between(t_bresenham b_dt, float ratio)
{
	t_argb	p1;
	t_argb	p2;
	t_argb	res;

	p1 = int_to_argb(b_dt.p1.color);
	p2 = int_to_argb(b_dt.p2.color);
	res.alpha = p1.alpha + ((p2.alpha - p1.alpha) * ratio);
	res.red = p1.red + ((p2.red - p1.red) * ratio);
	res.green = p1.green + ((p2.green - p1.green) * ratio);
	res.blue = p1.blue + ((p2.blue - p1.blue) * ratio);
	return (argb_to_int(res));
}
