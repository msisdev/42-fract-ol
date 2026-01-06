/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unproject.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:10:10 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/06 16:47:49 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_point	gl_pixel_to_point(t_state s, t_pixel a)
{
	t_point	p;

	p.x = a.x * s.s;
	p.y = a.y * s.s;
	return (p);
}
