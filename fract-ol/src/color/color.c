/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:37:11 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 20:29:43 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	color(t_fract f, t_color_mode m)
{
	if (m == COLOR_MODE_BLACK_WHITE)
		return (color_black_white(f));
	return (color_black_white(f));
}
