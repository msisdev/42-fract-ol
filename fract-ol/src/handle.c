/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:34:24 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/07 20:09:24 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_loop_routine(t_context *c)
{
	draw_fract(&c->d, &c->i, &c->s);
	ctx_display(c);
	return (0);
}
