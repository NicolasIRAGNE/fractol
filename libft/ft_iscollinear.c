/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscollinear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/31 13:50:07 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iscollinear(t_vector *v, t_vector *w)
{
	if ((v->x * w->y) - (v->y * w->x))
		return (0);
	return (1);
}
