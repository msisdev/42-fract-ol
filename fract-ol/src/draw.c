/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:43:16 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/05 14:23:51 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_point2d	add_point(t_point2d a, t_point2d b)
{
	t_point2d	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

void	draw_point(t_display *d, t_point2d p, t_color c)
{
	t_addr	dst;

	if (p.x < 0 || WINDOW_W <= p.x || p.y < 0 || WINDOW_H <= p.y)
		return ;
	dst = d->addr + p.y * d->_ll + (p.x * d->_bpp / 8);
	*(unsigned int *)dst = c;
}

void	draw_circle(t_display *d, t_point2d p, int r, t_color c)
{
	t_point2d	i;

	i.x = -r;
	while (i.x <= r)
	{
		i.y = -r;
		while (i.y <= r)
		{
			if (i.x * i.x + i.y * i.y <= r * r)
				draw_point(d, add_point(p, i), c);
			i.y++;
		}
		i.x++;
	}
}
