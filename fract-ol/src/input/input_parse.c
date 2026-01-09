/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:19:12 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/09 15:32:36 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_fract_mode	input_parse_fmode(const char *s)
{
	if (*s == 'm')
		return (FRACT_MODE_MANDEL);
	if (*s == 'j')
		return (FRACT_MODE_JULIA);
	return (FRACT_MODE_MANDEL);
}

t_color_mode	input_parse_cmode(const char *s)
{
	if (ft_strncmp(ARG_OPT_CMODE_BW, s,
			ft_strlen(ARG_OPT_CMODE_BW) == 0))
		return (COLOR_MODE_BLACK_WHITE);
	return (COLOR_MODE_BLACK_WHITE);
}

static long double	parse_fraction(const char *s)
{
	long double	n;

	n = 0;
	if (!*s)
		return (0);
	if (*s)
		n += parse_fraction(s + 1);
	n += *s - '0';
	n /= 10;
	return (n);
}

long double	input_parse_ld(const char *s)
{
	long double	sign;
	long double	n;
	char		*p;

	if (*s == '-')
		sign = -1;
	else
		sign = 1;
	n = (long double)ft_atoi(s);
	p = ft_strchr(s, '.');
	if (p)
		n += sign * parse_fraction(p + 1);
	return (n);
}
