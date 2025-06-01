/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakbas <omakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:53:12 by omakbas           #+#    #+#             */
/*   Updated: 2025/03/24 19:44:38 by omakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_arg_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{		
		if (!ft_isdigit(str[i]) && str[i] != '.'
			&& (str[i] != '-' && str[i] != '+'))
		{
			putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && (!ft_strncmp(av[1], "mandelbrot", 10)))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			check_arg_format(av[2]);
			fractal.julia_x = ft_atodbl(av[2]);
			check_arg_format(av[2]);
			fractal.julia_y = ft_atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		events_init(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
