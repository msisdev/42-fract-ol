/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:12:06 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/05 16:26:16 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//	(x + yi) + (u + vi) = (x + u) + (y + v)i
t_point	comp_add(t_point a, t_point b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_point	comp_sub(t_point a, t_point b)
{
	b.x *= -1;
	b.y *= -1;
	return (comp_add(a, b));
}

//	(a + bi)(c + di) = ac - bd + (ad + bc)i
t_point	comp_mul(t_point a, t_point b)
{
	t_point	c;

	c.x = (a.x * b.x) - (a.y * b.y);
	c.y = (a.x * b.y) + (a.y * b.x);
	return (c);
}

//	return square of absolute value.
long double	comp_abs_sq(t_point a)
{
	return ((a.x * a.x) + (a.y * a.y));
}

//	return square of the distance.
long double	comp_dis_sq(t_point a, t_point b)
{
	return (comp_abs_sq(comp_sub(a, b)));
}
