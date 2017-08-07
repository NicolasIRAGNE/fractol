/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:41:37 by niragne           #+#    #+#             */
/*   Updated: 2017/08/07 15:15:19 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook_mandel(int keycode, t_env *e)
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
	mandelbrot(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom}); //zoom = 2 x = -1 y = -1
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	return (0);
}

int mouse_hook_mandel(int button, int x, int y, t_env *e)
{	
	if (button == 1)
	{
		e->x = x * e->zoom / WIN_X;
		e->y = y * e->zoom / WIN_Y;
		//e->zoom *= 2;
		printf("%d %d\n",x * e->zoom / WIN_X, y * e->zoom / WIN_Y);
	}
	else if (button == 2)
	{

	}
	else if (button == 4 || button == 6)
	{

	}
	else if (button == 5 || button == 7)
	{
		
	}
	ft_clear_image(&e->image, 0x0);
	mandelbrot(e, (t_dpoint){e->x, e->y}, (t_dpoint){e->zoom, e->zoom});
	return(1);
}

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