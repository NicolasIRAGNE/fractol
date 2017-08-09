/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:54:07 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 18:51:42 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_clear_image(t_image *img, t_uint color)
{
	int		i;
	int		size;

	size = img->w * img->h;
	i = 0;
	while (i < size)
	{
		img->data[i] = color;
		i++;
	}
}

t_image		ft_new_image(void *mlx, int x, int y)
{
	t_image		ret;

	ret.image = mlx_new_image(mlx, x, y);
	ret.data = (t_uint *)mlx_get_data_addr(ret.image, &ret.bpp,
											&ret.w, &ret.endian);
	ret.w >>= 2;
	ret.h = y;
	return (ret);
}

void		ft_putpixel_secure(t_image *img, int x, int y, t_uint color)
{
	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
		img->data[x + y * img->w] = color;
}

void		ft_putpixel(t_image *img, int x, int y, t_uint color)
{
	img->data[x + y * img->w] = color;
}

void		ft_fillpixels(t_env *e, int x, int y, t_uint color)
{
	int i;
	int j;

	if (!(FLAGS & FLAG_FILL))
	{
		ft_putpixel(&e->image, x, y, color);
		return ;
	}
	i = 0;
	while (i < DX)
	{
		j = 0;
		while (j < DY)
		{
			ft_putpixel_secure(&e->image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
	