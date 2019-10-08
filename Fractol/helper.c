/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:35:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/08 16:36:09 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int				do_chosen_fractal(t_data *data)
{
	if (data->fractal == 1)
		julia(data);
	if (data->fractal == 2)
		mandelbrot(data);
	if (data->fractal == 3)
		multibrot(data);
	if (data->fractal == 4)
		burningship(data);
	return (1);
}

void			tmp_bits(unsigned int *tmp)
{
	int	i;

	i = 0;
	while (i < WIN_H * WIN_W)
	{
		tmp[i] = 0;
		i++;
	}
}

int				errors(int reason)
{
	if (reason == 0)
	{
		ft_putstr_fd("Arguments error.\n", 2);
		exit(0);
	}
	if (reason == 1)
	{
		ft_putstr_fd("Malloc error : data.\n", 2);
		exit(0);
	}
	if (reason == 2)
	{
		ft_putstr_fd("Invalid name of fractal.\n", 2);
		ft_putstr_fd("Choice one of: mandelbrot, julia, burningship\
	or multibrot.\n", 2);
		exit(0);
	}
	if (reason == 3)
	{
		ft_putstr_fd("MLX not found.\n", 2);
		exit(0);
	}
	return (1);
}
