/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:37 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 21:09:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook_julia(int keycode, t_env *e)
{
	static void (*f[300])(t_env *, int) = {NULL};

	if (f[0] == NULL)
		fill_hook_tab(f);
	if (keycode == 53)
		exit(0);
	f[keycode](e, keycode);
	ft_clear_image(&e->image, 0x0);
	julia(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom},
	(t_dpoint){e->a, e->b});
	display_info(e);
	return (0);
}

int		mouse_hook_julia1(int x, int y, t_env *e)
{
	if (FLAGS & FLAG_STOP)
	{
		e->a = x * ZOOM / WIN_X + X;
		e->b = y * ZOOM / WIN_Y + Y;
	}
	if (FLAGS & FLAG_PSYCH)
	{
		if (COLOR == 0)
			COLOR = 4;
		else if (COLOR == 4)
			COLOR = 8;
		else if (COLOR == 8)
			COLOR = 12;
		else if (COLOR == 12)
			COLOR = 16;
		else if (COLOR == 16)
			COLOR = 0;
		else
			COLOR = 0;
	}
	ft_clear_image(&e->image, 0x0);
	julia(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom},
	(t_dpoint){e->a, e->b});
	display_info(e);
	return (0);
}

int		mouse_hook_julia2(int button, int x, int y, t_env *e)
{
	if (button == 1 || button == 5)
		ft_zoom(e, x, y);
	else if (button == 2 || button == 4)
		ft_dezoom(e, x, y);
	ft_clear_image(&e->image, 0x0);
	julia(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom},
	(t_dpoint){e->a, e->b});
	display_info(e);
	return (1);
}

void	julia(t_env *e, t_dpoint a, t_dpoint b, t_dpoint cursor)
{
	double nb[3];

	nb[1] = 0;
	while (nb[1] < WIN_Y)
	{
		nb[0] = 0;
		while (nb[0] < WIN_X)
		{
			nb[2] = -1;
			Z = (t_cplx){nb[0] * b.x / WIN_X + a.x, nb[1] * b.y / WIN_Y + a.y};
			C = (t_cplx){cursor.x, cursor.y};
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
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}
