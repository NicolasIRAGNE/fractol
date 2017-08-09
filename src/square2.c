/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 18:52:10 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 19:02:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
