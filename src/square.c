/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:31:50 by niragne           #+#    #+#             */
/*   Updated: 2017/08/07 13:58:07 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		key_hook_sq(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_LEFT)
		e->x -= 1;
	else if (keycode == KEY_RIGHT)
		e->x += 1;
	else if (keycode == KEY_UP)
		e->y -= 1;
	else if (keycode == KEY_DOWN)
		e->y += 1;
	else if (keycode == KEY_PAD_ADD)
		e->zoom *= 2;
	else if (keycode == KEY_PAD_SUB)
		e->zoom /= 2;
	else if (keycode == KEY_O && e->it <= WIN_X / 2)
		e->it *= 2;
	else if (keycode == KEY_P && e->it >= 8)
		e->it /= 2;
	ft_clear_image(&e->image, 0xffffff);
	square(e, (t_point2d){e->x, e->y}, e->zoom);
	mlx_put_image_to_window(e->mlx, e->win, e->image.image, 0, 0);
	return (0);
}

int mouse_hook_sq(int button, int x, int y, t_env *e)
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
	square(e, (t_point2d){e->x, e->y}, e->zoom);

	//julia(e, (t_dpoint){-1, -1}, (t_dpoint){2, 2}, (t_dpoint){x, y});
	return(1);
}


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