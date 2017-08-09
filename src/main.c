/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:15:52 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 21:09:05 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

int main(int ac, char **av)
{
	t_env	e;
	init_flags(&e, av[1]);
	parse_flags(&e, av, ac);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.win_x, e.win_y, "fractol");
	e.image = ft_new_image(e.mlx, e.win_x, e.win_y);
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		mlx_hook(e.win, 2, 3, key_hook_mandel, &e);
		mlx_mouse_hook(e.win, mouse_hook_mandel, &e);
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		e.x = -1;
		e.y = -1;
		e.zoom = 2;
		mlx_mouse_hook(e.win, mouse_hook_julia2, &e);
		mlx_hook(e.win, 6, 3, mouse_hook_julia1, &e);
		mlx_hook(e.win, 2, 3, key_hook_julia, &e);
	}
	else if (ft_strcmp(av[1], "square") == 0)
	{
		mlx_hook(e.win, 2, 3, key_hook_sq, &e);
		mlx_mouse_hook(e.win, mouse_hook_sq, &e); //6 3
	}
	else
		exit(1);
	mlx_loop(e.mlx);
}
