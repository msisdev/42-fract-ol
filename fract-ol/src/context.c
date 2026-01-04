/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:36:29 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/04 15:28:29 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ctx_init(t_context *c)
{
	t_vars	*v;

	v = &c->v;
	v->mlx = mlx_init();
	if (!v->mlx)
		exit(1);
	v->win = mlx_new_window(v->mlx, WINDOW_W, WINDOW_H, WINDOW_T);
	if (!v->win)
		exit(1);
	dis_init(v->mlx, &c->d);
}

void	ctx_display(const t_context *c)
{
	mlx_put_image_to_window(c->v.mlx, c->v.win, c->d.img, 0, 0);
}

void	ctx_hook(const t_context *c, t_event e, t_mask m, int (*f)())
{
	t_vars	*v;

	v = (t_vars *)&c->v;
	mlx_hook(v->win, e, m, f, v);
}

void	ctx_loop(const t_context *c)
{
	mlx_loop(c->v.mlx);
}

