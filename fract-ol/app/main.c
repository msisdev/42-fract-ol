/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:05:19 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 15:35:20 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 *	USAGE
 *
 *		./fractol [-m (m|j)] [-jr <float num>] [-ji <float num>] [-c]
 *
 *	JULIA CONST VALUE RECS
 *
 * 		- `-jr -0.5125 -ji 0.5213`
 */
int	main(int argc, char *argv[])
{
	t_context		c;

	ctx_init(&c, argc, argv);
	ctx_display(&c);
	ctx_hook_event(&c, EVENT_KEY_PRESS, MASK_KEY_PRESS, handle_key_press);
	mlx_mouse_hook(c.win, handle_button_press, &c);
	ctx_hook_event(&c, EVENT_DESTROY_NOTIFY, 0, handle_destroy);
	ctx_hook_loop(&c, handle_loop_routine);
	ctx_loop(&c);
	return (0);
}
