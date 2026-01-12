/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:39:10 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/12 14:44:52 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static long double	calc_init_scale(void)
{
	long double	px_len;

	if (WINDOW_W > WINDOW_H)
		px_len = WINDOW_H;
	else
		px_len = WINDOW_W;
	return (STATE_INIT_WORLD_LEN / px_len);
}

void	ctx_state_init(t_state *s)
{
	s->center.x = 0;
	s->center.y = 0;
	s->scale = calc_init_scale();
	s->px = 0;
	s->px_max = WINDOW_W * WINDOW_H;
}

void	ctx_state_refresh(t_state *s)
{
	s->px = 0;
}
