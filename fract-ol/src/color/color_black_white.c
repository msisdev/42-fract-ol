/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:27:31 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 20:27:40 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	color_black_white(t_fract f)
{
	if (f.i % 2 == 0)
		return (PALETTE_BLACK);
	return (PALETTE_WHITE);
}
