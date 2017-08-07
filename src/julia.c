/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:37 by niragne           #+#    #+#             */
/*   Updated: 2017/08/07 13:50:10 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook_julia(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_RIGHT)
		e->x -= 0.1;
	else if (keycode == KEY_LEFT)
		e->x += 0.1;
	else if (keycode == KEY_UP)
		e->y -= 0.1;
	else if (keycode == KEY_DOWN)
		e->y += 0.1;
	else if (keycode == KEY_PAD_ADD)
		e->zoom *= 2;
	else if (keycode == KEY_PAD_SUB)
		e->zoom /= 2;
	else if (keycode == KEY_O && e->it <= WIN_X / 2)
		e->it *= 2;
	else if (keycode == KEY_P && e->it >= 8)
		e->it /= 2;
	ft_clear_image(&e->image, 0);
	square(e, (t_point2d){e->x, e->y}, e->zoom);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	return (0);
}

int mouse_hook_julia(int button, int x, int y, t_env *e)
{	
	if (button == 1)
	{
		e->x = x - e->zoom / 2;
		e->y = y - e->zoom / 2;
	}
	else if (button == 2)
	{
		e->x = x;
		e->y = y;
	}
	else if (button == 4 || button == 6)
	{
		e->x += e->zoom / 2;
		e->y += e->zoom / 2;
		e->zoom *= 1.1;
		e->x -= (x - e->x) * 0.1;
		e->y -= (y - e->y) * 0.1;
		e->x -= e->zoom / 2;
		e->y -= e->zoom / 2;
	}
	else if (button == 5 || button == 7)
	{
		e->x += e->zoom / 2;
		e->y += e->zoom / 2;
		e->zoom /= 1.1;
		e->x -= (x - e->x) / -11;
		e->y -= (y - e->y) / -11;
		e->x -= e->zoom / 2;
		e->y -= e->zoom / 2;
	}
	ft_clear_image(&e->image, 0xffffff);
	julia(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom}, (t_dpoint){x, y});
	return(1);
}

void	julia(t_env *e, t_dpoint a, t_dpoint size, t_dpoint cursor)
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
			z = cplx_new(x * size.x / WIN_X + a.x, y * size.y / WIN_Y + a.y);
			c = cplx_new(cursor.x * size.x / WIN_X, cursor.y * size.y / WIN_Y);
			while (i < e->it)
			{
				if (z.rel * z.rel + z.im * z.im > 4)
					break;
				z = cplx_add(cplx_mult(z, z), c);
				i++;
			}
			if (i != e->it)
				ft_putpixel(&e->image,x ,y, (i * 2) << 16);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}