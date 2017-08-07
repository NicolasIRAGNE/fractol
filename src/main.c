/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:15:52 by niragne           #+#    #+#             */
/*   Updated: 2017/08/07 20:33:14 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

int main(int ac, char **av)
{
	t_env	e;
	(void)ac;
	(void)av;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fractol");
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		e.it = 50;
		e.x = -1;
		e.y = -1;
		e.zoom = 2;
		mlx_hook(e.win, 2, 3, key_hook_mandel, &e);
		mlx_mouse_hook(e.win, mouse_hook_mandel, &e);
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		
	}
	else if (ft_strcmp(av[1], "square") == 0)
	{
		e.it = 50;
		e.x = WIN_X / 4;
		e.y = WIN_Y / 4;
		e.zoom = WIN_X / 4;
		mlx_hook(e.win, 2, 3, key_hook_sq, &e);
		mlx_mouse_hook(e.win, mouse_hook_sq, &e); //6 3
	}
	else
		exit(1);
	e.image = ft_new_image(e.mlx, WIN_X, WIN_Y);
	mlx_loop(e.mlx);
}
