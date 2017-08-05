/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:37 by niragne           #+#    #+#             */
/*   Updated: 2017/08/05 17:29:53 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *e, t_dpoint a, t_dpoint size)
{
	double x;
	double y;
	int i;
	t_cplx z;
	t_cplx c;

	y = 0;
	while(y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			i = 0;
			z = (t_cplx){0, 0};
			c = (t_cplx){x * size.x / WIN_X + a.x, y * size.y / WIN_Y + a.y};
			while (i < e->it)
			{
				if (z.rel * z.rel + z.im * z.im > 4)
					break;
				z = (t_cplx){z.rel * z.rel - z.im * z.im + c.rel, z.rel * z.im * 2 + c.im};
				i++;
			}
			if (i != e->it)
				ft_putpixel(&e->image,x ,y, (i * 2) << i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}