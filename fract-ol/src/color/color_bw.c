/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:27:31 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/12 14:51:17 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	color_bw(t_fract f)
{
	if (f.i % 2 == 0)
		return (PALETTE_BLACK);
	return (PALETTE_WHITE);
}
