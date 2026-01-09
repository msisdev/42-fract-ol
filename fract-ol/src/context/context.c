/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:36:29 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 15:03:55 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ctx_init(t_context *c, int argc, char *argv[])
{
	c->mlx = mlx_init();
	if (!c->mlx)
		exit(1);
	c->win = mlx_new_window(c->mlx, WINDOW_W, WINDOW_H, WINDOW_T);
	if (!c->win)
		exit(1);
	dis_init(c->mlx, &c->d);
	input_init(&c->i, argc, argv);
	state_init(&c->s);
}

void	ctx_display(const t_context *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->d.img, 0, 0);
}

void	ctx_loop(const t_context *c)
{
	mlx_loop(c->mlx);
}

