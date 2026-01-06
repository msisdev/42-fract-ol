/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:39:10 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/06 16:40:52 by minseobk         ###   ########.fr       */
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

void	state_init(t_state *s)
{
	s->c.x = 0;
	s->c.y = 0;
	s->s = calc_init_scale();
}
