/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:26:46 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 13:54:32 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_fract	fract_calc(t_point z, t_point c, unsigned int max_iter)
{
	t_fract	f;
	t_point	t;

	f.z = z;
	f.c = c;
	f.i = 0;
	while (f.i < max_iter)
	{
		t.x = f.z.x * f.z.x;
		t.y = f.z.y * f.z.y;
		if (t.x + t.y > 4.0)
			break ;
		f.z.y = 2 * f.z.x * f.z.y + f.c.y;
		f.z.x = t.x - t.y + f.c.x;
		f.i++;
	}
	return (f);
}

/**
 *	RETURN
 *
 *		Returns the iteration count (escape speed).
 *		Points in the set return max_iter.
 */
t_fract	fract_mandel(t_point c, unsigned int max_iter)
{
	t_point	z;

	z.x = 0;
	z.y = 0;
	return (fract_calc(z, c, max_iter));
}

t_fract	fract_julia(t_point z, t_point c, unsigned int max_iter)
{
	return (fract_calc(z, c, max_iter));
}

bool	fract_is_in_set(unsigned int last_iter, unsigned int max_iter)
{
	return (last_iter == max_iter);
}
