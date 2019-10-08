/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:51:01 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/07 15:19:55 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int		expected_fractal(char *av)
{
	if (((ft_strcmp(av, "julia") && \
		(ft_strcmp(av, "Julia"))) && \
		((ft_strcmp(av, "mandelbrot")) && \
		(ft_strcmp(av, "Mandelbrot"))) &&\
		((ft_strcmp(av, "multibrot")) && \
		(ft_strcmp(av, "Multibrot"))) &&
		(ft_strcmp(av, "Burningship")) &&
		(ft_strcmp(av, "burningship"))))
		return (1);
	return (0);
}

static	void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_H, WIN_W, "fractal");
	data->image = mlx_new_image(data->mlx, WIN_H, WIN_W);
	data->tmp = (unsigned int *)mlx_get_data_addr(data->image, &data->bpp, \
		&data->line, &data->endian);
}

int				main(int ac, char **av)
{
	t_data	*data;

	if (ac < 2)
		errors(0);
	if (expected_fractal(av[1]))
		errors(2);
	if (!(data = init_data()))
		errors(1);
	init_window(data);
	choice_of_fractal(av[1], data);
	do_chosen_fractal(data);
	mlx_key_hook(data->window, (void *)keys, data);
	mlx_mouse_hook(data->window, (void *)mouse, data);
	mlx_hook(data->window, 6, 0, dancing_julia, data);
	mlx_hook(data->window, 17, 0, (void *)close_window, data);
	mlx_loop(data->mlx);
}
