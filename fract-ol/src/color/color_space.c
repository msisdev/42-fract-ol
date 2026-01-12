/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:47:32 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/12 14:47:39 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#define NORM_BAILOUT 100

#define COLOR_SPACE_TRUNK 0xD4D3DD
#define COLOR_SPACE_BG_A 0x1D2B64
#define COLOR_SPACE_BG_B 0xF8CDDA

static long double	norm(long double n)
{
	if (n == FRACT_MAX_ITER)
		return (1);
	if (n > FRACT_MAX_ITER)
		n -= FRACT_MAX_ITER;
	return (n / FRACT_MAX_ITER);
}

t_color	color_space(t_fract f)
{
	if (f.i >= FRACT_MAX_ITER)
		return (COLOR_SPACE_TRUNK);
	return (color_interp(COLOR_SPACE_BG_A, COLOR_SPACE_BG_B, norm(f.s)));
}
