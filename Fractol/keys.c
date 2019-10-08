/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:06:01 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/07 18:45:24 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void			change_multi(int key, t_data *data)
{
	if (key == MAIN_PAD_R)
		data->pic->n++;
	if (key == MAIN_PAD_F && data->pic->n != 2)
		data->pic->n--;
}

void				keys(int key, t_data *data)
{
	if (key == MAIN_PAD_ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		free(data);
		exit(0);
	}
	if (key == ARROW_UP || key == MAIN_PAD_W)
		data->pic->y1 += 30 / data->pic->zoom;
	if (key == ARROW_DOWN || key == MAIN_PAD_S)
		data->pic->y1 -= 30 / data->pic->zoom;
	if (key == ARROW_LEFT || key == MAIN_PAD_A)
		data->pic->x1 += 30 / data->pic->zoom;
	if (key == ARROW_RIGHT || key == MAIN_PAD_D)
		data->pic->x1 -= 30 / data->pic->zoom;
	change_multi(key, data);
	do_chosen_fractal(data);
}

int					close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	free(data);
	exit(0);
}
