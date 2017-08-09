/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:00:28 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 17:32:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_info(t_env *e)
{
	char *it;
	char *mult;

	it = ft_itoa(IT);
	mult = ft_itoa(MULT);
	mlx_string_put(e->mlx, e->win, 0, 0, 0xffffff, it);
	mlx_string_put(e->mlx, e->win, 0, 25, 0xffffff, mult);
	free(it);
	free(mult);
}
