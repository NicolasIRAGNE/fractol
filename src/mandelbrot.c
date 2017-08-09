/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:37 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 18:47:50 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook_mandel(int keycode, t_env *e)
{
	static void (*f[300])(t_env *, int) = {NULL};

	if (f[0] == NULL)
		fill_hook_tab(f);
	if (keycode == 53)
		exit(0);
	f[keycode](e, keycode);
	ft_clear_image(&e->image, 0x0);
	mandelbrot(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom});
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	display_info(e);
	return (0);
}

int		mouse_hook_mandel(int button, int x, int y, t_env *e)
{
	if (button == 1 || button == 5)
		ft_zoom(e, x, y);
	else if (button == 2 || button == 4)
		ft_dezoom(e, x, y);
	ft_clear_image(&e->image, 0x0);
	display_info(e);
	mandelbrot(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom});
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	return (1);
}

void	mandelbrot(t_env *e, t_dpoint a, t_dpoint size)
{
	double nb[3];

	nb[1] = 0;
	while (nb[1] < WIN_Y)
	{
		nb[0] = 0;
		while (nb[0] < WIN_X)
		{
			nb[2] = -1;
			Z = (t_cplx){0, 0};
			C = (t_cplx){nb[0] * size.x / WIN_X + a.x,
			nb[1] * size.y / WIN_Y + a.y};
			while (++nb[2] < e->it)
			{
				if (Z.rel * Z.rel + Z.im * Z.im > 4)
					break ;
				Z = cplx_add(cplx_mult(Z, Z), C);
			}
			if (nb[2] != e->it)
				ft_fillpixels(e, nb[0], nb[1], ((int)nb[2] * MULT) <<
				(e->color + ((int)nb[2] * ((e->flags & 1) > 0))));
			nb[0] += e->dx;
		}
		nb[1] += e->dy;
	}
}
