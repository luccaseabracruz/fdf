/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_between.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:21:50 by lseabra-          #+#    #+#             */
/*   Updated: 2025/09/19 14:09:24 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_argb	int_to_argb(int color)
{
	t_argb	argb;

	argb.alpha = color >> 24 & 0xFF;
	argb.red = color >> 16 & 0xFF;
	argb.green = color >> 8 & 0xFF;
	argb.blue = color & 0xFF;
	return (argb);
}

static int	argb_to_int(t_argb argb)
{
	int	res;

	res = argb.alpha << 24;
	res += argb.red << 16;
	res += argb.green << 8;
	res += argb.blue;
	return (res);
}

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
