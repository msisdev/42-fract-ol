/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:24:47 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 20:25:46 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_fract_pixel(t_display *d, t_input *i, t_state *s, t_pixel a)
{
	t_point	p;
	t_fract	f;
	t_color	c;

	p = gl_pixel_to_point(a, s->center, s->scale);
	if (i->fmode == FRACT_MODE_MANDEL)
		f = fract_mandel(p, FRACT_MAX_ITER);
	else
		f = fract_julia(p, i->julia_c, FRACT_MAX_ITER);
	c = color(f, i->cmode);
	draw_pixel(d, a, c);
}

void	draw_fract_step(t_display *d, t_input *i, t_state *s)
{
	int			step;
	t_pixel		a;

	step = 0;
	a.x = s->px % WINDOW_W;
	a.y = s->px / WINDOW_W;
	while (step < STATE_PX_STEP_SIZE && s->px < s->px_max)
	{
		if (a.x + 1 < WINDOW_W)
			a.x += 1;
		else
		{
			a.x = 0;
			a.y += 1;
		}
		draw_fract_pixel(d, i, s, a);
		step++;
		s->px++;
	}
}

void	draw_fract(t_display *d, t_input *i, t_state *s)
{
	if (s->px < s->px_max)
		draw_fract_step(d, i, s);
}
