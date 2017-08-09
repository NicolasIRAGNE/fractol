/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 18:52:52 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 18:54:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	square_topleft(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size / 2, a.y + size / 2},
	0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y}, (t_point2d)
	{a.x + size, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x, a.y + size / 2}, (t_point2d)
	{a.x + size / 2, a.y + size}, 0b0);
}

void	square_topright(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size / 2, a.y + size / 2},
	0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y}, (t_point2d)
	{a.x + size, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y + size / 2},
	(t_point2d){a.x + size, a.y + size}, 0b0);
}

void	square_botleft(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, a, (t_point2d){a.x + size / 2, a.y + size / 2},
	0b0);
	square_filled(&e->image, (t_point2d){a.x, a.y + size / 2}, (t_point2d)
	{a.x + size / 2, a.y + size}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y + size / 2},
	(t_point2d){a.x + size, a.y + size}, 0b0);
}

void	square_botright(t_env *e, t_point2d a, int size)
{
	square_filled(&e->image, (t_point2d){a.x, a.y + size / 2}, (t_point2d)
	{a.x + size / 2, a.y + size}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y}, (t_point2d)
	{a.x + size, a.y + size / 2}, 0b0);
	square_filled(&e->image, (t_point2d){a.x + size / 2, a.y + size / 2},
	(t_point2d){a.x + size, a.y + size}, 0b0);
}
