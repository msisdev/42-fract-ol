/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:47:45 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/08 18:07:00 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ctx_hook_event(const t_context *c, t_event e, t_mask m, int (*f)())
{
	mlx_hook(c->win, e, m, f, (void *)c);
}

void	ctx_hook_loop(const t_context *c, int (*f)())
{
	mlx_loop_hook(c->mlx, f, (void *)c);
}
