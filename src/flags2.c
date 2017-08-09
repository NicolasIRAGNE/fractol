/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:35:35 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 17:36:01 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_env *e, char *str)
{
	if (ft_strequ(str, "red"))
		return (COLOR = 16);
	if (ft_strequ(str, "blue"))
		return (COLOR = 0);
	if (ft_strequ(str, "green"))
		return (COLOR = 8);
	return (-1);
}

int		get_mult(t_env *e, char *str)
{
	int mult;

	mult = ft_atoi(str);
	if (mult <= 0)
		MULT = 1;
	else
		MULT = mult;
	return (mult);
}

int		get_dx(t_env *e, char *str)
{
	int dx;

	dx = ft_atoi(str);
	if (dx <= 0)
		DX = 1;
	else
		DX = dx;
	return (dx);
}

int		get_dy(t_env *e, char *str)
{
	int dy;

	dy = ft_atoi(str);
	if (dy <= 0)
		DY = 1;
	else
		DY = dy;
	return (dy);
}

int		get_winx(t_env *e, char *str)
{
	int x;

	x = ft_atoi(str);
	if (x > 2560)
		WIN_X = 2560;
	else if (x <= 0)
		WIN_X = 100;
	else
		WIN_X = x;
	return (x);
}
