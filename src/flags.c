/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 15:32:30 by niragne           #+#    #+#             */
/*   Updated: 2017/08/09 21:10:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_flags(t_env *e, char *fractal)
{
	WIN_X = 750;
	WIN_Y = 750;
	FLAGS = 0;
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
		else if (str[i] == 'f')
			FLAGS |= FLAG_FILL;
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
	else if (ft_strequ(av + 1, "-fill"))
		FLAGS |= FLAG_FILL;
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
	if (DX >= WIN_X)
		DX = WIN_X - 1;
	if (DY >= WIN_Y)
		DY = WIN_Y - 1;
}
