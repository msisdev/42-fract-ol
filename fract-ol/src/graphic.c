/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:10:10 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/08 18:30:08 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_point	gl_pixel_to_point(t_pixel a, t_point center, long double scale)
{
	t_point	p;

	a.x -= WINDOW_W / 2;
	a.y -= WINDOW_H / 2;
	p.x = a.x * scale + center.x;
	p.y = a.y * scale + center.y;
	return (p);
}
