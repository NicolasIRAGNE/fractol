/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:12:52 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 17:32:10 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx	cplx_mult(t_cplx z1, t_cplx z2)
{
	t_cplx	ret;

	ret.rel = z1.rel * z2.rel - z1.im * z2.im;
	ret.im = z1.rel * z2.im + z2.rel * z1.im;
	return (ret);
}

t_cplx	cplx_new(double rel, double im)
{
	t_cplx ret;

	ret.rel = rel;
	ret.im = im;
	return (ret);
}

t_cplx	cplx_add(t_cplx z1, t_cplx z2)
{
	t_cplx ret;

	ret.rel = z1.rel + z2.rel;
	ret.im = z1.im + z2.im;
	return (ret);
}
