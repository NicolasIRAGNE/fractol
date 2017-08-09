/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 20:54:24 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 20:56:57 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_sq(t_image *image, t_point2d *a, t_point2d *b)
{
	if (a->x < 0)
		a->x = 0;
	if (a->y < 0)
		a->y = 0;
	if (a->x >= image->w)
		a->x = image->w;
	if (a->y >= image->h)
		a->y = image->h;
	if (b->x < 0)
		b->x = 0;
	if (b->y < 0)
		b->y = 0;
	if (b->x >= image->w)
		b->x = image->w;
	if (b->y >= image->h)
		b->y = image->h;
}
