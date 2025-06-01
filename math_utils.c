/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakbas <omakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 00:43:20 by omakbas           #+#    #+#             */
/*   Updated: 2025/03/24 18:36:00 by omakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_range	set_scale(double new_min, double new_max,
	double old_min, double old_max)
{
	t_range	ranges;

	ranges.new_min = new_min;
	ranges.new_max = new_max;
	ranges.old_min = old_min;
	ranges.old_max = old_max;
	return (ranges);
}

double	scale(double unscaled_num, t_range ranges)
{
	return (((ranges.new_max - ranges.new_min) * (unscaled_num - ranges.old_min)
			/ (ranges.old_max - ranges.old_min)) + ranges.new_min);
}

t_complex	ft_sum_comp(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	ft_square_comp(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * (z.x * z.y);
	return (res);
}
