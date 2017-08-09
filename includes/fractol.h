/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 14:15:40 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 20:55:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "keycodes.h"
# include <stdio.h>

# define WIN_X e->win_x
# define WIN_Y e->win_y
# define COLOR e->color
# define IT e->it
# define DX e->dx
# define DY e->dy
# define FLAGS e->flags
# define ZOOM e->zoom
# define X e->x
# define Y e->y
# define A e->a
# define B e->b
# define MULT e->mult
# define Z e->z
# define C e->c

# define FLAGLIST "Cehf"
# define FLAGARG "xyimc"

# define FLAG_CHELOU	(1 << 0)
# define FLAG_STOP		(1 << 1)
# define FLAG_PSYCH		(1 << 2)
# define FLAG_FILL		(1 << 3)

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
	double	x;
	double	y;
	double	zoom;
	double	a;
	double	b;
	int		dx;
	int		dy;
	t_uint	color;
	t_uint	flags;
	int		win_x;
	int		win_y;
	int		mult;
	t_cplx	z;
	t_cplx	c;
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
void		init_sq(t_image *image, t_point2d *a, t_point2d *b);
void		square_filled(t_image *image, t_point2d a, t_point2d b, t_uint color);
void		julia(t_env *e, t_dpoint a, t_dpoint size, t_dpoint cursor);
void		topleft(t_env *e, t_point2d a, int size);
void		topright(t_env *e, t_point2d a, int size);
void		botleft(t_env *e, t_point2d a, int size);
void		botright(t_env *e, t_point2d a, int size);
int			key_hook_sq(int keycode, t_env *e);
int 		mouse_hook_sq(int button, int x, int y, t_env *e);
int			key_hook_julia(int keycode, t_env *e);
int 		mouse_hook_julia1(int x, int y, t_env *e);
int 		mouse_hook_julia2(int button, int x, int y, t_env *e);
int			key_hook_mandel(int keycode, t_env *e);
int 		mouse_hook_mandel(int button, int x, int y, t_env *e);
void		parse_flags(t_env *e, char **av, int ac);
void		init_flags(t_env *e, char *fractal);
void		ft_puterr(char *str);
void		print_help(void);
void		hook_void(t_env *e, int keycode);
void		hook_arrow_key(t_env *e, int keycode);
void		hook_iter(t_env *e, int keycode);
void		hook_flags(t_env *e, int keycode);
void		hook_mult(t_env *e, int keycode);
void		hook_chelou(t_env *e, int keycode);
void		fill_hook_tab(void (**f)(t_env *, int));
void		ft_putpixel_secure(t_image *img, int x, int y, t_uint color);
void		display_info(t_env *e);
void		ft_zoom(t_env *e, int x, int y);
void		ft_dezoom(t_env *e, int x, int y);
int			get_winy(t_env *e, char *str);
int			get_winx(t_env *e, char *str);
int			get_color(t_env *e, char *str);
int			get_mult(t_env *e, char *str);
int			get_dx(t_env *e, char *str);
int			get_dy(t_env *e, char *str);
int			get_it(t_env *e, char *str);
void		ft_fillpixels(t_env *e, int x, int y, t_uint color);
void		topleft(t_env *e, t_point2d a, int size);
void		topright(t_env *e, t_point2d a, int size);
void		botleft(t_env *e, t_point2d a, int size);
void		botright(t_env *e, t_point2d a, int size);
void		square_topleft(t_env *e, t_point2d a, int size);
void		square_topright(t_env *e, t_point2d a, int size);
void		square_botleft(t_env *e, t_point2d a, int size);
void		square_botright(t_env *e, t_point2d a, int size);

#endif