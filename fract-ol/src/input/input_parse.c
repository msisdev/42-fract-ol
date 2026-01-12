/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:19:12 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/12 14:40:01 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_fract_mode	input_parse_fmode(const char *s)
{
	if (*s == 'm')
		return (FRACT_MODE_MANDEL);
	if (*s == 'j')
		return (FRACT_MODE_JULIA);
	input_invalid();
	return (FRACT_MODE_MANDEL);
}

t_color_mode	input_parse_cmode(const char *s)
{
	if (ft_strncmp(ARG_OPT_CMODE_BW, s,
			ft_strlen(ARG_OPT_CMODE_BW)) == 0)
		return (COLOR_MODE_BLACK_WHITE);
	if (ft_strncmp(ARG_OPT_CMODE_SPACE, s,
			ft_strlen(ARG_OPT_CMODE_SPACE)) == 0)
		return (COLOR_MODE_TREE);
	input_invalid();
	return (COLOR_MODE_BLACK_WHITE);
}

static void	validate_ld(const char *s)
{
	char	*p;

	if (!s || !*s)
		return ;
	if (*s == '-' || *s == '+')
		s++;
	p = ft_strchr(s, '.');
	if (p)
	{
		while (s != p)
		{
			if (!ft_isdigit(*s))
				input_invalid();
			s++;
		}
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
			input_invalid();
		s++;
	}
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

	validate_ld(s);
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
