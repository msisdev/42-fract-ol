/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:26:46 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/12 18:41:26 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static long double	get_smooth_value(unsigned int i, long double q)
{
	return (i + 1 - (logl(q)));
}

t_fract	fract_calc(t_point z, t_point c, unsigned int max_iter)
{
	t_fract		f;
	long double	x2;
	long double	y2;

	f.z = z;
	f.c = c;
	f.i = 0;
	while (f.i < max_iter)
	{
		x2 = f.z.x * f.z.x;
		y2 = f.z.y * f.z.y;
		if (x2 + y2 > FRACT_ESCAPE_THRESHOLD_SQ)
			break ;
		f.z.y = 2 * f.z.x * f.z.y + f.c.y;
		f.z.x = x2 - y2 + f.c.x;
		f.i++;
	}
	f.q = x2 + y2;
	if (f.i < max_iter)
		f.s = get_smooth_value(f.i, f.q);
	else
		f.s = f.i;
	return (f);
}

t_fract	fract(t_input *i, t_point p)
{
	t_point	z;

	if (i->fmode == FRACT_MODE_MANDEL)
	{
		z.x = 0;
		z.y = 0;
		return (fract_calc(z, p, FRACT_MAX_ITER));
	}
	else
		return (fract_calc(p, i->julia_c, FRACT_MAX_ITER));
}

bool	fract_is_in_set(unsigned int last_iter, unsigned int max_iter)
{
	return (last_iter == max_iter);
}
