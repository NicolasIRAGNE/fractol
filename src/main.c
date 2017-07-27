/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:15:52 by niragne           #+#    #+#             */
/*   Updated: 2017/07/27 21:51:52 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	static double a = -1;
	static double b = -1;
	static double c = 2;

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
		c -= 0.1;
	else if (keycode == KEY_PAD_SUB)
		c += 0.1;
	else if (keycode == KEY_O && e->it <= WIN_X / 2)
		e->it *= 2;
	else if (keycode == KEY_P && e->it >= 2)
		e->it /= 2;
	ft_clear_image(&e->image, 0xffffff);
	square(e, (t_point2d){WIN_X / 4, WIN_X / 4}, WIN_X / 2);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	return (0);
}

int main(int ac, char **av)
{
	t_env	e;
	(void)ac;
	(void)av;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fractol");
	e.image = ft_new_image(e.mlx, WIN_X, WIN_Y);
	e.it = 5;
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
}
