/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:15:40 by niragne           #+#    #+#             */
/*   Updated: 2017/08/05 17:29:09 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "keycodes.h"

# define WIN_X 500
# define WIN_Y 500
# define ITER_MAX 30

typedef unsigned int	t_uint;

typedef struct	s_image
{
	void	*image;
	t_uint	*data;
	int		bpp;
	int		w;
	int		h;
	int		endian;
}				t_image;

typedef struct s_cplx
{
	double rel;
	double im;
}				t_cplx;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_image image;
	int		it;
	int		x;
	int		y;
	int		zoom;
}				t_env;

typedef struct	s_dpoint
{
	double	x;
	double	y;
}				t_dpoint;

typedef struct	s_point2d
{
	int	x;
	int	y;
}				t_point2d;

t_cplx		cplx_mult(t_cplx z1, t_cplx z2);
t_cplx		cplx_new(double rel, double im);
t_cplx		cplx_add(t_cplx z1, t_cplx z2);
void		ft_clear_image(t_image *img, t_uint color);
t_image		ft_new_image(void *mlx, int x, int y);
void		ft_putpixel(t_image *img, int x, int y, t_uint color);
void		mandelbrot(t_env *e, t_dpoint a, t_dpoint size);
void		square(t_env *e, t_point2d a, int size);
void		square_filled(t_image *image, t_point2d a, t_point2d b, t_uint color);
void		julia(t_env *e, t_dpoint a, t_dpoint size, t_dpoint cursor);
void		topleft(t_env *e, t_point2d a, int size);
void		topright(t_env *e, t_point2d a, int size);
void		botleft(t_env *e, t_point2d a, int size);
void		botright(t_env *e, t_point2d a, int size);

#endif