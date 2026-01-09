/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:23:00 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 20:55:06 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#define NORM_BAILOUT 100 

static long double	norm(int n, long double q)
{
	return (
		n + 1 - (
			(logl(longl(q) * 0.5) - logl(logl(NORM_BAILOUT)))
			/ logl(2)
		)
	);
}

unsigned int lerp_color(unsigned int c1, unsigned int c2, float t)
{
	unsigned char	r1;
	unsigned char	r2;
	
	r1 = (c1 >> 16) & 0xFF, g1 = (c1 >> 8) & 0xFF, b1 = c1 & 0xFF;
	r2 = (c2 >> 16) & 0xFF, g2 = (c2 >> 8) & 0xFF, b2 = c2 & 0xFF;

	// Interpolate each channel
	unsigned char r = (unsigned char)(r1 + t * (r2 - r1));
	unsigned char g = (unsigned char)(g1 + t * (g2 - g1));
	unsigned char b = (unsigned char)(b1 + t * (b2 - b1));

	// Recombine into 0xRRGGBB
	return (r << 16) | (g << 8) | b;
}

t_color	color_tree(t_fract f)
{
	norm_up(f);
	return (0);
}
