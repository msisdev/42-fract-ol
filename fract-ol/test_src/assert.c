/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:49:03 by minseobk          #+#    #+#             */
/*   Updated: 2025/10/10 17:08:18 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	assert_msg(int expression, const char *fmt, ...)
{
	va_list	args;

	if (expression)
		return ;
	fprintf(stderr, "\n*** ASSERTION FAILURE ***\n");
	fprintf(stderr, "Message: ");
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fprintf(stderr, "\n*************************\n");
	abort();
}
