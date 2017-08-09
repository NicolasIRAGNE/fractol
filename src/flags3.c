/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:36:21 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 17:40:34 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_winy(t_env *e, char *str)
{
	int y;

	y = ft_atoi(str);
	if (y > 1440)
		WIN_Y = 1440;
	else if (y <= 0)
		WIN_Y = 100;
	else
		WIN_Y = y;
	return (y);
}

int		get_it(t_env *e, char *str)
{
	int it;

	it = ft_atoi(str);
	if (it > 255)
		IT = 255;
	else if (it <= 0)
		IT = 1;
	else
		IT = it;
	return (it);
}
