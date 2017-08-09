/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:26:27 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 17:30:30 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_env *e, int x, int y)
{
	double tmpx;
	double tmpy;
	double dx;
	double dy;
	double dx2;

	tmpx = ((double)x * ZOOM / WIN_X) + X;
	tmpy = ((double)y * ZOOM / WIN_Y) + Y;
	dx = (tmpx - X) / 2;
	dy = (tmpy - Y) / 2;
	dx2 = (X + ZOOM - tmpx) / 2;
	X += dx;
	Y += dy;
	ZOOM -= dx + dx2;
}

void	ft_dezoom(t_env *e, int x, int y)
{
	double tmpx;
	double tmpy;
	double dx;
	double dy;
	double dx2;

	tmpx = ((double)x * ZOOM / WIN_X) + X;
	tmpy = ((double)y * ZOOM / WIN_Y) + Y;
	dx = (tmpx - X) / 2;
	dy = (tmpy - Y) / 2;
	dx2 = (X + ZOOM - tmpx) / 2;
	e->x -= dx;
	e->y -= dy;
	e->zoom += dx + dx2;
}
