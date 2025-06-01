/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakbas <omakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:48:53 by omakbas           #+#    #+#             */
/*   Updated: 2025/03/24 17:30:33 by omakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	ismandel_or_isjulia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale(x, set_scale(-2, +2, 0, WIDTH))
			* fractal->zoom) + fractal->move_x;
	z.y = (scale(y, set_scale(+2, -2, 0, HEIGHT))
			* fractal->zoom) + fractal->move_y;
	ismandel_or_isjulia(&z, &c, fractal);
	while (i < fractal->iteration_limit)
	{
		z = ft_sum_comp(ft_square_comp(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_val)
		{
			color = scale(i, set_scale(BLACK, WHITE, 0,
						fractal->iteration_limit));
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, AQUA_DREAM);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	if (fractal->img.img_ptr)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
				WIDTH,
				HEIGHT);
	}
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0,
		0);
}
