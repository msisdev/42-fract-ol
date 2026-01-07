/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:10:10 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/06 17:14:44 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_point	gl_pixel_to_point(t_pixel a, long double scale)
{
	t_point	p;

	p.x = a.x * scale;
	p.y = a.y * scale;
	return (p);
}
