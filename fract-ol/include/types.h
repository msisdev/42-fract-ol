/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:27:54 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/06 14:40:20 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef unsigned int	t_color;
typedef char			*t_addr;

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

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_point
{
	long double	x;
	long double	y;
}	t_point;

/**
 *	FIELDS
 *
 *		- `z`: initial value of z
 *		- `c`: initial value of c
 * 		- `i`: last iteration count
 * 		- `q`: square value of the last sequence number
 */
typedef struct s_fract
{
	t_point			z;
	t_point			c;
	unsigned int	i;
	long double		q;
}	t_fract;

typedef enum e_coloring
{
	COLORING_BLACK_WHITE,
}	t_coloring;

#endif // TYPES_H
