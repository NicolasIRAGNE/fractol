/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:31:50 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 20:56:25 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		key_hook_sq(int keycode, t_env *e)
{
	static void (*f[300])(t_env *, int) = {NULL};

	if (f[0] == NULL)
		fill_hook_tab(f);
	if (keycode == 53)
		exit(0);
	f[keycode](e, keycode);
	ft_clear_image(&e->image, 0x0);
	ft_clear_image(&e->image, 0xffffff);
	square(e, (t_point2d){X, Y}, ZOOM);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	display_info(e);
	return (0);
}

void	zoom_sq(t_env *e, int button, int x, int y)
{
	if (button == 1 || button == 5)
	{
		X += ZOOM / 2;
		Y += ZOOM / 2;
		ZOOM *= 1.1;
		X -= (x - X) * 0.1;
		Y -= (y - Y) * 0.1;
		X -= ZOOM / 2;
		Y -= ZOOM / 2;
	}
	else if (button == 2 || button == 4)
	{
		X += ZOOM / 2;
		Y += ZOOM / 2;
		ZOOM /= 1.1;
		X -= (x - X) / -11;
		Y -= (y - Y) / -11;
		X -= ZOOM / 2;
		Y -= ZOOM / 2;
	}
}

int		mouse_hook_sq(int button, int x, int y, t_env *e)
{
	zoom_sq(e, button, x, y);
	ft_clear_image(&e->image, 0xffffff);
	square(e, (t_point2d){X, Y}, ZOOM);
	return (1);
}

void	square_filled(t_image *image, t_point2d a, t_point2d b, t_uint color)
{
	int x;
	int y;

	y = a.y;
	while (y < b.y)
	{
		x = a.x;
		while (x < b.x)
		{
			ft_putpixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	square(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size, a.y + size}, 0b0);
	if (e->it >= WIN_X / 2)
		return ;
	square_topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	square_topright(e, (t_point2d){a.x + 3 * size
	/ 4, a.y - size / 4}, size / 2);
	square_botleft(e, (t_point2d){a.x - size / 4,
	a.y + 3 * size / 4}, size / 2);
	square_botright(e, (t_point2d){a.x + 3
	* size / 4, a.y + 3 * size / 4}, size / 2);
	topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
	botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}
