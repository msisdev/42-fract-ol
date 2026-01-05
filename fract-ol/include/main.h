/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:03:12 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/05 15:58:46 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_types.h"
# include "types.h"
# define WIN_W 1440
# define WIN_H 900
# define WIN_T "Hello, World!"

typedef struct s_display
{
	void	*img;
	t_addr	addr;
	int		_bpp;
	int		_ll;
	int		_end;
}	t_display;

typedef struct s_state
{
	int	frame;
}	t_state;

typedef struct s_context
{
	void		*mlx;
	void		*win;
	t_display	d;
	t_state		s;
}	t_context;

/* context.c */
void		ctx_init(t_context *c);
void		ctx_display(const t_context *c);
void		ctx_hook_event(const t_context *c, t_event e, t_mask m, int (*f)());
void		ctx_hook_loop(const t_context *c, int (*f)());
void		ctx_loop(const t_context *c);

/* display.c */
void		dis_init(void *mlx_ptr, t_display *d);

/* draw.c */
t_pixel		add_pixel(t_pixel a, t_pixel b);
void		draw_pixel(t_display *d, t_pixel p, t_color c);
void		draw_circle(t_display *d, t_pixel p, int r, t_color c);

/* state.c */
void		state_init(t_state *s);

#endif // MAIN_H
