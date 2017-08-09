/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:52:42 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 17:43:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_void(t_env *e, int keycode)
{
	(void)e;
	(void)keycode;
}

void	hook_arrow_key(t_env *e, int keycode)
{
	if (keycode == KEY_RIGHT)
		X -= 0.1;
	else if (keycode == KEY_LEFT)
		X += 0.1;
	else if (keycode == KEY_UP)
		Y -= 0.1;
	else if (keycode == KEY_DOWN)
		Y += 0.1;
}

void	hook_iter(t_env *e, int keycode)
{
	if (keycode == KEY_P && e->it < 256)
		IT++;
	else if (keycode == KEY_O && e->it > 1)
		IT--;
}

void	hook_flags(t_env *e, int keycode)
{
	if (keycode == KEY_S)
		FLAGS ^= FLAG_STOP;
	else if (keycode == KEY_D)
		FLAGS ^= FLAG_PSYCH;
}

void	hook_mult(t_env *e, int keycode)
{
	if (keycode == KEY_L)
		MULT++;
	else if (keycode == KEY_K && MULT > 1)
		MULT--;
}
