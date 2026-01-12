/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:34:24 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/12 14:46:09 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	handle_loop_routine(t_context *c)
{
	draw_fract(&c->d, &c->i, &c->s);
	ctx_display(c);
	return (0);
}

int	handle_destroy(t_context *c)
{
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_image(c->mlx, c->d.img);
	mlx_destroy_display(c->mlx);
	free(c->mlx);
	exit(0);
	return (0);
}

int	handle_key_press(int code, t_context *c)
{
	if (code == KEY_ESC)
		handle_destroy(c);
	else if (code == KEY_LEFT)
	{
		c->s.center.x -= STATE_MOVE_STEP * c->s.scale;
		ctx_state_refresh(&c->s);
	}
	else if (code == KEY_UP)
	{
		c->s.center.y -= STATE_MOVE_STEP * c->s.scale;
		ctx_state_refresh(&c->s);
	}
	else if (code == KEY_RIGHT)
	{
		c->s.center.x += STATE_MOVE_STEP * c->s.scale;
		ctx_state_refresh(&c->s);
	}
	else if (code == KEY_DOWN)
	{
		c->s.center.y += STATE_MOVE_STEP * c->s.scale;
		ctx_state_refresh(&c->s);
	}
	return (0);
}

static void	log_pixel(t_pixel a, t_point p, t_fract f, t_color c)
{
	printf("[info] pixel(%d, %d) point(%Lf, %Lf) i(%u) s(%Lf) color(%x)\n",
		a.x, a.y,
		p.x, p.y,
		f.i,
		f.s,
		c);
}

int	handle_button_press(int code, int x, int y, t_context *c)
{
	t_pixel	a;
	t_fract	f;

	if (code == MOUSE_LEFT_CLICK)
	{
		a.x = x;
		a.y = y;
		c->s.center = gl_pixel_to_point(a, c->s.center, c->s.scale);
		f = fract(&c->i, c->s.center);
		log_pixel(a, c->s.center, f, color(f, c->i.cmode));
		ctx_state_refresh(&c->s);
	}
	else if (code == MOUSE_SCROLL_UP)
	{
		c->s.scale /= STATE_SCALE_STEP;
		ctx_state_refresh(&c->s);
	}
	else if (code == MOUSE_SCROLL_DOWN)
	{
		c->s.scale *= STATE_SCALE_STEP;
		ctx_state_refresh(&c->s);
	}
	return (0);
}
