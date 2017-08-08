/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 15:32:30 by niragne           #+#    #+#             */
/*   Updated: 2017/08/08 21:28:38 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_env *e, char *str)
{
	if (ft_strequ(str, "red"))
		return (COLOR = 16);
	if (ft_strequ(str, "blue"))
		return (COLOR = 0);
	if (ft_strequ(str, "green"))
		return (COLOR = 8);
	return (-1);
}

int		get_mult(t_env *e, char *str)
{
	int mult;

	mult = ft_atoi(str);
	if (mult <= 0)
		MULT = 1;
	else
		MULT = mult;
	return (mult);
}

int		get_dx(t_env *e, char *str)
{
	int dx;

	dx = ft_atoi(str);
	if (dx <= 0)
		DX = 1;
	else
		DX = dx;
	return (dx);
}

int		get_dy(t_env *e, char *str)
{
	int dy;

	dy = ft_atoi(str);
	if (dy <= 0)
		DY = 1;
	else
		DY = dy;
	return (dy);
}

int		get_winx(t_env *e, char *str)
{
	int x;

	x = ft_atoi(str);
	if (x > 2560)
		WIN_X = 2560;
	else if (x <= 0)
		WIN_X = 100;
	else
		WIN_X = x;
	return (x);
}

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

void	init_flags(t_env *e, char *fractal)
{
	WIN_X = 750;
	WIN_Y = 750;
	if (ft_strequ("square", fractal))
		ZOOM = WIN_X / 2;
	else
		ZOOM = 2;
	IT = 50;
	DX = 1;
	DY = 1;
	X = -1;
	Y = -1;
	MULT = 8;
	FLAGS ^= FLAG_STOP;
}

void	parse_single(t_env *e, char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'C')
			FLAGS |= FLAG_CHELOU;
		else if (str[i] == 'e')
			FLAGS |= FLAG_PSYCH;
		else if (str[i] == 'h')
			print_help();
		else
			ft_puterr("invalid argument\n");
		i++;
	}
}

void	parse_words(t_env *e, char *av, char *param)
{
	if (ft_strequ(av + 1, "c"))
		get_color(e, param);
	else if (ft_strequ(av + 1, "i"))
		get_it(e, param);
	else if (ft_strequ(av + 1, "-dx"))
		get_dx(e, param);
	else if (ft_strequ(av + 1, "-dy"))
		get_dy(e, param);
	else if (ft_strequ(av + 1, "x"))
		get_winx(e, param);
	else if (ft_strequ(av + 1, "y"))
		get_winy(e, param);
	else if (ft_strequ(av + 1, "-chelou"))
		FLAGS |= FLAG_CHELOU;
	else if (ft_strequ(av + 1, "m"))
		get_mult(e, param);
	else
		ft_puterr("invalid argument\n");
}

void	parse_flags(t_env *e, char **av, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == '-' || ft_strchr(FLAGARG, av[i][1]))
				parse_words(e, av[i], av[i + 1]);
			else
				parse_single(e, av[i]);
		}
		i++;
	}
}
































