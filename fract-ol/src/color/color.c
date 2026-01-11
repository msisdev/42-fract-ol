/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:37:11 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/11 17:16:39 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 *	DESCRIPTION
 *
 *		- if x == 0, return a.
 *		- if x == 1, return b.
 */
t_color	color_interp(t_color u, t_color v, long double x)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (x <= 0)
		return (u);
	if (x >= 1)
		return (v);
	t = ((u >> 24) & 0xFF) * (1.0 - x) + ((v >> 24) & 0xFF) * x + 0.5;
	r = ((u >> 16) & 0xFF) * (1.0 - x) + ((v >> 16) & 0xFF) * x + 0.5;
	g = ((u >> 8) & 0xFF) * (1.0 - x) + ((v >> 8) & 0xFF) * x + 0.5;
	b = (u & 0xFF) * (1.0 - x) + (v & 0xFF) * x + 0.5;
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	color_stepper(t_color u, t_color v, long double x)
{
	if ((long long)x % 2 == 0)
		return (u);
	return (v);
}

t_color	color(t_fract f, t_color_mode m)
{
	if (m == COLOR_MODE_BLACK_WHITE)
		return (color_black_white(f));
	if (m == COLOR_MODE_TREE)
		return (color_space(f));
	return (color_black_white(f));
}
