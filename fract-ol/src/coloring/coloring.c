/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:37:11 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/06 15:06:50 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	color_black_white(t_fract f)
{
	if (f.i % 2 == 0)
		return (PALETTE_BLACK);
	return (PALETTE_WHITE);
}

t_color	color_get(t_fract f, t_coloring c)
{
	if (c == COLORING_BLACK_WHITE)
		return (color_black_white(f));
	return (color_black_white(f));
}
