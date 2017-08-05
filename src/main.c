/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:15:52 by niragne           #+#    #+#             */
/*   Updated: 2017/08/05 14:26:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	static double a = -1;
	static double b = -1;
	static double c = 2;
	(void)c;

	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_RIGHT)
		a -= 0.1;
	else if (keycode == KEY_LEFT)
		a += 0.1;
	else if (keycode == KEY_UP)
		b -= 0.1;
	else if (keycode == KEY_DOWN)
		b += 0.1;
	else if (keycode == KEY_PAD_ADD)
		e->zoom *= 2;
	else if (keycode == KEY_PAD_SUB)
		e->zoom /= 2;
	else if (keycode == KEY_O && e->it <= WIN_X / 2)
		e->it *= 2;
	else if (keycode == KEY_P && e->it >= 8)
		e->it /= 2;
	printf("%d\n", keycode);
	//ft_clear_image(&e->image, 0xffffff);
	//mandelbrot(e, (t_dpoint){-1, -1}, (t_dpoint){2, 2});
	//square(e, (t_point2d){e->x, e->y}, e->zoom);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	int dx;
	int dy;
	(void)button;
	
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
	else if (button == 6)
	{
		dx = e->x + e->zoom / 2 - x;
		dy = e->y + e->zoom / 2 - y;
		e->x -= dx;
		e->y -= dy;
		e->zoom *= 1.1;
		e->x += dx * 1.1;
		e->y += dy * 1.1;
	}
	else if (button == 7)
	{
		e->zoom /= 1.1;
		e->x = x - e->zoom / 2;
		e->y = y - e->zoom / 2;
		printf("%d %d\n", e->x, e->y);
	}
	printf("%d %d %d \n",button, x, y );
	//ft_clear_image(&e->image, 0xffffff);
	//square(e, (t_point2d){e->x, e->y}, e->zoom);

	//julia(e, (t_dpoint){-1, -1}, (t_dpoint){2, 2}, (t_dpoint){x, y});
	return(1);
}

int main(int ac, char **av)
{
	t_env	e;
	(void)ac;
	(void)av;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fractol");
	e.image = ft_new_image(e.mlx, WIN_X, WIN_Y);
	square_filled(&e.image, (t_point2d){0,0}, (t_point2d){500, 500}, 0xffffff);
	mlx_put_image_to_window(e.mlx, e.win, e.image.image, 0, 0);
	/*
	e.it = 50;
	e.x = WIN_X / 4;
	e.y = WIN_Y / 4;
	e.zoom = WIN_X / 4;
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e); //6 3*/
	mlx_loop(e.mlx);
}
