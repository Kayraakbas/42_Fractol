/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakbas <omakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:53:15 by omakbas           #+#    #+#             */
/*   Updated: 2025/03/24 18:19:28 by omakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300
# define ERROR_MESSAGE "Please enter arguments in proper format"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_range
{
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}	t_range;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	char	*name;
	double	x;
	double	y;
	double	escape_val;
	int		iteration_limit;
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

void		putstr_fd(char *s, int fd);
int			ft_strncmp(char *s1, char *s2, int n);
double		ft_atodbl(char *str);
int			ft_isdigit(char c);
t_complex	ft_sum_comp(t_complex z1, t_complex z2);
t_complex	ft_square_comp(t_complex z1);
double		scale(double unscaled_num, t_range put_ranges);
void		fractal_render(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			close_win(t_fractal *fractal);
int			mouse_handler(int keycode, int x, int y, t_fractal *fractal);
t_range		set_scale(double new_min, double new_max,
				double old_min, double old_max);
#endif
