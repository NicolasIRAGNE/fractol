/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:01:30 by niragne           #+#    #+#             */
/*   Updated: 2017/08/08 21:20:12 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(void)
{
	ft_putstr(\
"O / P: increase/decrease iterations\n\
ARROW KEYS: move fractal\n\
S : Enable or disable mouse on julia\n\
D : Enable or disable psych mode\n\
Right click / Mouse wheel down: Zoom\n\
Left click / Mouse wheel up: Dezoom\n");
}