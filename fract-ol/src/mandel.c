/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:26:46 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/05 16:44:20 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 *	RETURN
 *
 *		Returns the iteration count (escape speed).
 *		Points in the set return max_iter.
 */
int	mandel_escape_speed(t_point c, int max_iter)
{
	t_point	z;
	int		i;

	z.x = 0;
	z.y = 0;
	i = 0;
	while (i < max_iter)
	{
		z = comp_add(comp_mul(z, z), c);
		if (comp_abs_sq(z) > 4.0)
			return (i);
		i++;
	}
	return (max_iter);
}

bool	mandel_is_in_set(int escape_speed, int max_iter)
{
	return (escape_speed == max_iter);
}
