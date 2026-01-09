/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:03:12 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 14:00:20 by minseobk         ###   ########.fr       */
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
# define WINDOW_T "fractol"
# define STATE_INIT_WORLD_LEN 4.0
# define STATE_PX_STEP_SIZE 1000000
# define STATE_SCALE_STEP 1.1
# define STATE_MOVE_STEP 100
# define FRACT_MAX_ITER 100

/**
 *	FIELDS
 */
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
 *		- `julia_c`: constant value for julia set sequence
 */
typedef struct s_input
{
	t_fract_mode	fmode;
	t_color_mode	cmode;
	t_point			julia_c;
}	t_input;

/**
 *	FIELDS
 *
 *		- `center`:	center of the world
 *		- `scale`:	scale value (pixel * scale = world)
 *		- `px`:		current drawn pixels
 *		- `px_max`:	max value of `px`
 */
typedef struct s_state
{
	t_point			center;
	long double		scale;
	int				px;
	int				px_max;
}	t_state;

typedef struct s_context
{
	void		*mlx;
	void		*win;
	t_display	d;
	t_input		i;
	t_state		s;
}	t_context;

/* colorize */
t_color		colorize(t_fract f, t_color_mode m);
t_color		color_black_white(t_fract f);

/* context */
void		ctx_init(t_context *c);
void		ctx_display(const t_context *c);
t_pixel		ctx_get_mouse_pos(const t_context *c);
void		ctx_hook_event(const t_context *c, t_event e, t_mask m, int (*f)());
void		ctx_hook_loop(const t_context *c, int (*f)());
void		ctx_loop(const t_context *c);

/* display */
void		dis_init(void *mlx_ptr, t_display *d);

/* draw */
t_pixel		add_pixel(t_pixel a, t_pixel b);
void		draw_pixel(t_display *d, t_pixel a, t_color c);
void		draw_circle(t_display *d, t_pixel a, int r, t_color c);
void		draw_fract(t_display *d, t_input *i, t_state *s);
void		draw_fract_step(t_display *d, t_input *i, t_state *s);
void		draw_fract_pixel(t_display *d, t_input *i, t_state *s, t_pixel a);

/* fractal */
t_fract		fract_mandel(t_point c, unsigned int max_iter);
t_fract		fract_julia(t_point z, t_point c, unsigned int max_iter);
bool		fract_is_in_set(unsigned int last_iter, unsigned int max_iter);

/* graphic */
t_point		gl_pixel_to_point(t_pixel a, t_point center, long double scale);

/* handle */
int			handle_loop_routine(t_context *c);
int			handle_destroy(t_context *c);
int			handle_key_press(int keycode, t_context *c);
int			handle_button_press(int code, int x, int y, t_context *c);

/* input */
void		input_init(t_input *i);

/* state */
void		state_init(t_state *s);
void		state_refresh(t_state *s);

#endif // MAIN_H
