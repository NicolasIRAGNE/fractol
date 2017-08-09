/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_tab_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:58:47 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 17:43:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_hook_tab(void (**f)(t_env *, int))
{
	int i;

	i = 0;
	while (i < 300)
	{
		f[i] = hook_void;
		i++;
	}
	f[KEY_RIGHT] = hook_arrow_key;
	f[KEY_DOWN] = hook_arrow_key;
	f[KEY_UP] = hook_arrow_key;
	f[KEY_LEFT] = hook_arrow_key;
	f[KEY_P] = hook_iter;
	f[KEY_O] = hook_iter;
	f[KEY_S] = hook_flags;
	f[KEY_D] = hook_flags;
	f[KEY_L] = hook_mult;
	f[KEY_K] = hook_mult;
	f[KEY_F] = hook_chelou;
}
