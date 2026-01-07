/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:31:08 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/07 20:27:13 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	input_init(t_input *i)
{
	i->fmode = FRACT_MODE_JULIA;
	i->cmode = COLOR_MODE_BLACK_WHITE;
	i->julia_c.x = -0.618;
	i->julia_c.y = 0;
}
