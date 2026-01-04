/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:03:12 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/04 19:26:42 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_types.h"
# define WINDOW_W 1920
# define WINDOW_H 1080
# define WINDOW_T "Hello"

typedef int		t_color;
typedef char	*t_addr;

typedef struct s_display
{
	void	*img;
	t_addr	addr;
	int		_bpp;
	int		_ll;
	int		_end;
}	t_display;

typedef struct s_context
{
	void		*mlx;
	void		*win;
	t_display	d;
}	t_context;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef enum e_palette
{
	PALETTE_RED = 0x00ff0000,
	PALETTE_GREEN = 0x0000ff00,
	PALETTE_BLUE = 0x000000ff,
	PALETTE_WHITE = 0x00ffffff,
	PALETTE_BLACK = 0x00000000,
	PALETTE_YELLOW = 0x00ffff00,
	PALETTE_CYAN = 0x0000ffff,
	PALETTE_MAGENTA = 0x00ff00ff,
}	t_palette;

/* context.c */
void	ctx_init(t_context *c);
void	ctx_display(const t_context *c);
void	ctx_hook(const t_context *c, t_event e, t_mask m, int (*f)());
void	ctx_loop(const t_context *c);

/* display.c */
void	dis_init(void *mlx_ptr, t_display *d);

/* draw.c */
t_point	add_point(t_point a, t_point b);
void	draw_point(t_display *d, t_point p, t_color c);
void	draw_circle(t_display *d, t_point p, int r, t_color c);

#endif // MAIN_H
