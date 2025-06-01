/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakbas <omakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:46:09 by omakbas           #+#    #+#             */
/*   Updated: 2025/03/23 22:33:40 by omakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int keycode, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (keycode == 4)
	{
		fractal->zoom *= 1.05;
	}
	else if (keycode == 5)
	{
		fractal->zoom *= 0.95;
	}
	fractal_render(fractal);
	return (0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		close_win(fractal);
	else if (keycode == XK_Up)
		fractal->move_y += (0.5 * fractal->zoom);
	else if (keycode == XK_Down)
		fractal->move_y -= (0.5 * fractal->zoom);
	else if (keycode == XK_Left)
		fractal->move_x -= (0.5 * fractal->zoom);
	else if (keycode == XK_Right)
		fractal->move_x += (0.5 * fractal->zoom);
	else if (keycode == XK_4)
		fractal->iteration_limit += 10;
	else if (keycode == XK_minus)
		fractal->iteration_limit -= 10;
	fractal_render(fractal);
	return (0);
}
