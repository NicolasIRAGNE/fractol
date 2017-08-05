/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:31:50 by niragne           #+#    #+#             */
/*   Updated: 2017/08/05 17:19:28 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	square_filled(t_image *image, t_point2d a, t_point2d b, t_uint color)
{
	int x;
	int y;

	if (a.x < 0)
		a.x = 0;
	if (a.y < 0)
		a.y = 0;
	if (a.x >= image->w)
		a.x = image->w;
	if (a.y >= image->h)
		a.y = image->h;
	if (b.x < 0)
		b.x = 0;
	if (b.y < 0)
		b.y = 0;
	if (b.x >= image->w)
		b.x = image->w;
	if (b.y >= image->h)
		b.y = image->h;
	y = a.y;
	while (y < b.y)
	{
		x = a.x;
		while (x < b.x)
		{
			ft_putpixel(image, x ,y, color);
			x++;
		}
		y++;
	}
}

void	square_topleft(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size / 2, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y}, (t_point2d){a.x + size, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x, a.y + size / 2}, (t_point2d){a.x + size / 2, a.y + size}, 0b0);
}

void	square_topright(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size / 2, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y}, (t_point2d){a.x + size, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y + size / 2}, (t_point2d){a.x + size, a.y + size}, 0b0);
}

void	square_botleft(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size / 2, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x, a.y + size / 2}, (t_point2d){a.x + size / 2, a.y + size}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y + size / 2}, (t_point2d){a.x + size, a.y + size}, 0b0);
}

void	square_botright(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, (t_point2d){a.x, a.y + size / 2}, (t_point2d){a.x + size / 2, a.y + size}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y}, (t_point2d){a.x + size, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y + size / 2}, (t_point2d){a.x + size, a.y + size}, 0b0);
}

void	topleft(t_env *e, t_point2d a, int size)
{
	if (size < e->it)
		return ;
	square_topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	square_topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	square_botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
	if (a.x + size / 2 >= 0 && a.y + size / 2 >= 0)
		topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	if (a.y + size / 2 >= 0)
		topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	if (a.x + size / 2 >= 0)
		botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
}

void	topright(t_env *e, t_point2d a, int size)
{
	if (size < e->it)
		return ;
	square_topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	square_topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	square_botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	if (a.y + size / 2 >= 0)
		topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	if (a.x + size / 2 <= WIN_X && a.y + size / 2 >= 0)
		topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	if (a.x + size / 2 <= WIN_X)
		botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
}

void	botleft(t_env *e, t_point2d a, int size)
{
	if (size < e->it)
		return ;
	square_topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	square_botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	square_botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
	if (a.x + size / 2 >= 0)
		topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	if (a.y + size / 2 <= WIN_Y)
		botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	if (a.x + size / 2 >= 0 && a.y + size / 2 <= WIN_Y)
		botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
}

void	botright(t_env *e, t_point2d a, int size)
{
	if (size < e->it)
		return ;
	square_botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	square_topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	square_botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
	if (a.x + size / 2 <= WIN_X && a.y + size / 2 <= WIN_Y)
		botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	if (a.x + size / 2 <= WIN_X)
		topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	if (a.y + size / 2 <= WIN_Y)
		botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
}

void	square(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size, a.y + size}, 0b0);
	if (e->it >= WIN_X / 2)
		return ;
	square_topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	square_topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	square_botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
	square_botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	topleft(e, (t_point2d){a.x - size / 4, a.y - size / 4}, size / 2);
	topright(e, (t_point2d){a.x + 3 * size / 4, a.y - size / 4}, size / 2);
	botleft(e, (t_point2d){a.x - size / 4, a.y + 3 * size / 4}, size / 2);
	botright(e, (t_point2d){a.x + 3 * size / 4, a.y + 3 * size / 4}, size / 2);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
}