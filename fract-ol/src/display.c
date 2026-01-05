/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:33:24 by minseobk          #+#    #+#             */
/*   Updated: 2026/01/05 15:54:27 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	dis_init(void *mlx_ptr, t_display *d)
{
	d->img = mlx_new_image(mlx_ptr, WIN_W, WIN_H);
	if (!d->img)
		exit(1);
	d->addr = mlx_get_data_addr(d->img, &d->_bpp, &d->_ll, &d->_end);
	if (!d->addr)
		exit(1);
}
