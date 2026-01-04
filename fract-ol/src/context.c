/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:36:29 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/04 19:26:15 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ctx_init(t_context *c)
{
	c->mlx = mlx_init();
	if (!c->mlx)
		exit(1);
	c->win = mlx_new_window(c->mlx, WINDOW_W, WINDOW_H, WINDOW_T);
	if (!c->win)
		exit(1);
	dis_init(c->mlx, &c->d);
}

void	ctx_display(const t_context *c)
{
	mlx_put_image_to_window(c->mlx, c->win, c->d.img, 0, 0);
}

void	ctx_hook(const t_context *c, t_event e, t_mask m, int (*f)())
{
	mlx_hook(c->win, e, m, f, (void *)c);
}

void	ctx_loop(const t_context *c)
{
	mlx_loop(c->mlx);
}

