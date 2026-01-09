/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:31:08 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 15:30:06 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 *	FAMOUS JULIA VALUE
 *
 *		- `(-0.5125, 0.5213)`
 */
static void	input_fill_const(t_input *i)
{
	i->fmode = FRACT_MODE_MANDEL;
	i->cmode = COLOR_MODE_BLACK_WHITE;
	i->julia_c.x = -0.5125;
	i->julia_c.y = 0.5213;
}

static void	parse_opt(t_input *i, int *idx, char *argv[])
{
	if (ft_strncmp(ARG_OPT_FMODE_NAME, argv[*idx],
			ft_strlen(ARG_OPT_FMODE_NAME)) == 0)
	{
		i->fmode = input_parse_fmode(argv[*idx + 1]);
		*idx += 2;
	}
	else if (ft_strncmp(ARG_OPT_CMODE_NAME, argv[*idx],
			ft_strlen(ARG_OPT_CMODE_NAME)) == 0)
	{
		i->cmode = input_parse_cmode(argv[*idx + 1]);
		*idx += 2;
	}
	else if (ft_strncmp(ARG_OPT_JULIA_R_NAME, argv[*idx],
			ft_strlen(ARG_OPT_JULIA_R_NAME)) == 0)
	{
		i->julia_c.x = input_parse_cmode(argv[*idx + 1]);
		*idx += 2;
	}
	else if (ft_strncmp(ARG_OPT_JULIA_I_NAME, argv[*idx],
			ft_strlen(ARG_OPT_JULIA_I_NAME)) == 0)
	{
		i->julia_c.y = input_parse_ld(argv[*idx + 1]);
		*idx += 2;
	}
}

void	input_init(t_input *i, int argc, char *argv[])
{
	int	idx;

	input_fill_const(i);
	idx = 0;
	while (idx < argc)
	{
		if (argv[idx][0] == '-')
			parse_opt(i, &idx, argv);
		else
			idx++;
	}
}
