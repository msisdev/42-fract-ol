/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:43:16 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/12 14:48:07 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_pixel	add_pixel(t_pixel a, t_pixel b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

void	draw_pixel(t_display *d, t_pixel a, t_color c)
{
	t_addr	dst;

	if (a.x < 0 || WINDOW_W <= a.x || a.y < 0 || WINDOW_H <= a.y)
		return ;
	dst = d->addr + a.y * d->_ll + (a.x * d->_bpp / 8);
	*(t_color *)dst = c;
}

void	draw_circle(t_display *d, t_pixel a, int r, t_color c)
{
	t_pixel	i;

	i.x = -r;
	while (i.x <= r)
	{
		i.y = -r;
		while (i.y <= r)
		{
			if (i.x * i.x + i.y * i.y <= r * r)
				draw_pixel(d, add_pixel(a, i), c);
			i.y++;
		}
		i.x++;
	}
}
