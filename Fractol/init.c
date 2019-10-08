/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:58:07 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/07 18:29:20 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		init_julia(t_data *data)
{
	data->pic->x1 = -2;
	data->pic->y1 = -2;
	data->pix->cx = -1;
	data->pic->pause = 0;
	data->pix->cy = 0.305;
	data->pic->zoom = 350;
	data->pic->it_max = 50;
}

static void		init_fractals(t_data *data)
{
	data->pic->x1 = -2;
	data->pic->y1 = -2;
	data->pic->zoom = 400;
	data->pic->it_max = 50;
	data->pic->n = 6;
}

t_data			*init_data(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))) ||
	!(data->pic = malloc(sizeof(t_picture))) ||
	(!(data->pix = malloc(sizeof(t_pixels)))))
		errors(1);
	return (data);
}

void			choice_of_fractal(char *av, t_data *data)
{
	if (!(ft_strcmp(av, "Julia")) || !(ft_strcmp(av, "julia")))
	{
		init_julia(data);
		data->fractal = 1;
	}
	if (!(ft_strcmp(av, "Mandelbrot")) || (!ft_strcmp(av, "mandelbrot")))
	{
		init_fractals(data);
		data->fractal = 2;
	}
	if (!(ft_strcmp(av, "multibrot") || !(ft_strcmp(av, "Multibrot"))))
	{
		init_fractals(data);
		data->fractal = 3;
	}
	if (!(ft_strcmp(av, "burningship") || !(ft_strcmp(av, "Burningship"))))
	{
		init_fractals(data);
		data->fractal = 4;
	}
}
