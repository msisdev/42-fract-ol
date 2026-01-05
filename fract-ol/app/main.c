/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:05:19 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/05 15:58:02 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

static int	handle_key_press(int keycode, t_context *c)
{
	(void)keycode;
	mlx_destroy_window(c->mlx, c->win);
	exit(0);
	return (0);
}

static int	handle_loop(t_context *c)
{
	int	t;

	t = c->s.frame + 1;
	if (t == 1000000)
		t = 0;
	if (t % 100000 == 0)
		printf("frame: %d\n", t);
	c->s.frame = t;
	return (0);
}

int	main(void)
{
	const t_pixel	center = {.x = WIN_W / 2, .y = WIN_H / 2};
	t_context		c;

	ctx_init(&c);
	draw_circle(&c.d, center, 200, PALETTE_MAGENTA);
	ctx_display(&c);
	ctx_hook_event(&c, EVENT_KEY_PRESS, MASK_KEY_PRESS, handle_key_press);
	ctx_hook_loop(&c, handle_loop);
	ctx_loop(&c);
	return (0);
}
