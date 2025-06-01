/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakbas <omakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:03:31 by omakbas           #+#    #+#             */
/*   Updated: 2025/03/23 22:33:55 by omakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	putstr_fd("Problems with malloc", 1);
	exit (1);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_val = 4;
	fractal->iteration_limit = 42;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, ON_DESTROY, 1L << 19, close_win, fractal);
	mlx_hook(fractal->mlx_window, ON_KEYDOWN, 1L << 0, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ON_MOUSEDOWN, 1L << 2,
		mouse_handler,
		fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
}
