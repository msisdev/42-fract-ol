/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:49:45 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/08 18:16:28 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_pixel	ctx_get_mouse_pos(const t_context *c)
{
	t_pixel	a;

	mlx_mouse_get_pos(c->mlx, c->win, &a.x, &a.y);
	return (a);
}
