/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayraakbas <kayraakbas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:08:34 by kayraakbas        #+#    #+#             */
/*   Updated: 2025/03/13 17:08:50 by kayraakbas       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main ()
{
    t_fractol z;
    t_fractol s;
    int count;
    double temp_real;
    count = 42;
    z.reel = 0;
    z.imaginaire = 0;

    s.reel = 0.25;
    s.imaginaire = 0.4;

    for (int i = 0; i < count; i++)
    {
        temp_real = (z.reel * z.reel) - (z.imaginaire * z.imaginaire);
        z.imaginaire = 2 * z.reel * z.imaginaire;
        z.reel = temp_real;

        z.reel += s.reel;
        z.imaginaire += s.imaginaire;

        printf("index: %d  z.reel = %f z.imaginaire = %f \n",i, z.reel, z.imaginaire);
    }
    
    return (0);
}