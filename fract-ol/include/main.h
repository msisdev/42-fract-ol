/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:03:12 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/06 16:42:52 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_types.h"
# include "types.h"
# define WINDOW_W 1440
# define WINDOW_H 900
# define WINDOW_T "Hello, World!"
# define STATE_INIT_WORLD_LEN 2.0
# define FRACT_STEP 100

typedef struct s_display
{
	void	*img;
	t_addr	addr;
	int		_bpp;
	int		_ll;
	int		_end;
}	t_display;

/**
 *	FIELDS
 *
 *		- `c`: center of the world
 *		- `s`: scale value (pixel * scale = world)
 */
typedef struct s_state
{
	t_point		c;
	long double	s;
}	t_state;

typedef struct s_context
{
	void		*mlx;
	void		*win;
	t_display	d;
	t_state		s;
}	t_context;

/* coloring */
t_color		color_get(t_fract f, t_coloring c);
t_color		color_black_white(t_fract f);

/* context */
void		ctx_init(t_context *c);
void		ctx_display(const t_context *c);
void		ctx_hook_event(const t_context *c, t_event e, t_mask m, int (*f)());
void		ctx_hook_loop(const t_context *c, int (*f)());
void		ctx_loop(const t_context *c);

/* display */
void		dis_init(void *mlx_ptr, t_display *d);

/* draw */
t_pixel		add_pixel(t_pixel a, t_pixel b);
void		draw_pixel(t_display *d, t_pixel p, t_color c);
void		draw_circle(t_display *d, t_pixel p, int r, t_color c);

/* fractal */
t_fract		mandel_sequence(t_point c, int max_iter);
t_fract		julia_sequence(t_point z, t_point c, unsigned int max_iter);
bool		fract_is_in_set(t_fract f);

/* state */
void		state_init(t_state *s);

#endif // MAIN_H
