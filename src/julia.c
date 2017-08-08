/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:37 by niragne           #+#    #+#             */
/*   Updated: 2017/08/08 21:23:23 by niragne          ###   ########.fr       */
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
	else if (keycode == KEY_P && e->it < 256)
		e->it++;
	else if (keycode == KEY_O && e->it > 1)
		e->it--;
	else if (keycode == KEY_S)
		FLAGS ^= FLAG_STOP;
	else if (keycode == KEY_D)
		FLAGS ^= FLAG_PSYCH;
	ft_clear_image(&e->image, 0x0);
	julia(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom}, (t_dpoint){e->a, e->b});
	mlx_string_put(e->mlx, e->win, 0, 0, 0xffffff, ft_itoa(e->it));
	return (0);
}

int mouse_hook_julia1(int x, int y, t_env *e)
{
	if (FLAGS & FLAG_STOP)
	{
		e->a = x * ZOOM / WIN_X + X;
		e->b = y * ZOOM / WIN_Y + Y;
	}
	if (FLAGS & FLAG_PSYCH)
	{
		if (COLOR == 0)
			COLOR = 8;
		else if (COLOR == 8)
			COLOR = 16;
		else if (COLOR == 16)
			COLOR = 0;
	}
	ft_clear_image(&e->image, 0x0);
	julia(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom}, (t_dpoint){e->a, e->b});
	mlx_string_put(e->mlx, e->win, 0, 0, 0xffffff, ft_itoa(e->it));
	return(1);
}

int mouse_hook_julia2(int button, int x, int y, t_env *e)
{
	double tmpx;
	double tmpy;
	double dx;
	double dy;
	double dx2;
	double dy2;

	if (button == 1)
	{
		tmpx = ((double)x * e->zoom / WIN_X) + e->x;
		tmpy = ((double)y * e->zoom / WIN_Y) + e->y;
		dx = (tmpx - e->x) / 2;
		dy = (tmpy - e->y) / 2;
		dx2 = (e->x + e->zoom - tmpx) / 2;
		dy2 = (e->y + e->zoom - tmpy) / 2;
		e->x += dx;
		e->y += dy;
		e->zoom -= dx + dx2;
	}
	else if (button == 2)
	{
		tmpx = ((double)x * e->zoom / WIN_X) + e->x;
		tmpy = ((double)y * e->zoom / WIN_Y) + e->y;
		dx = (tmpx - e->x) / 2;
		dy = (tmpy - e->y) / 2;
		dx2 = (e->x + e->zoom - tmpx) / 2;
		dy2 = (e->y + e->zoom - tmpy) / 2;
		e->x -= dx;
		e->y -= dy;
		e->zoom += dx + dx2;
	}
	else if (button == 4 || button == 6)
	{

	}
	else if (button == 5 || button == 7)
	{
		
	}
	ft_clear_image(&e->image, 0x0);
	julia(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom}, (t_dpoint){e->a, e->b});
	mlx_string_put(e->mlx, e->win, 0, 0, 0xffffff, ft_itoa(e->it));
	return (1);
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
			c = cplx_new(cursor.x, cursor.y);
			while (i < e->it)
			{
				if (z.rel * z.rel + z.im * z.im > 4)
					break;
				z = cplx_add(cplx_mult(z, z), c);
				i++;
			}
			if (i != e->it)
				ft_putpixel(&e->image,x ,y, (i * MULT) << (e->color + (i * ((e->flags & 1) > 0))));
			x += e->dx;
		}
		y += e->dy;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}