/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:05:19 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/04 15:40:01 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_close(int keycode, t_vars *v)
{
	(void)keycode;
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
	return (0);
}

int	main(void)
{
	const t_point	center = {.x = WINDOW_W / 2, .y = WINDOW_H / 2};
	t_context		c;

	ctx_init(&c);
	draw_circle(&c.d, center, 200, PALETTE_MAGENTA);
	ctx_display(&c);
	ctx_hook(&c, EVENT_KEY_PRESS, MASK_KEY_PRESS, handle_close);
	ctx_loop(&c);
	return (0);
}
