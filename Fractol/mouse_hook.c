/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:35:49 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/07 18:32:23 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int				dancing_julia(int x, int y, void *data)
{
	if (((t_data *)data)->pic->pause == 0 && ((t_data *)data)->fractal == 1)
	{
		((t_data *)data)->pix->cx = (double)x / 500 - 1.3;
		((t_data *)data)->pix->cy = (double)y / 500 - 1.3;
		julia(data);
	}
	return (0);
}

static void		rev_zoom(int x, int y, t_data *data)
{
	data->pic->x1 = (x / data->pic->zoom + data->pic->x1) - \
	(x / (data->pic->zoom / 1.3));
	data->pic->y1 = (y / data->pic->zoom + data->pic->y1) - \
	(y / (data->pic->zoom / 1.3));
	data->pic->zoom /= 1.3;
	data->pic->it_max--;
}

static void		zoom(int x, int y, t_data *data)
{
	data->pic->x1 = (x / data->pic->zoom + data->pic->x1) - \
	(x / (data->pic->zoom * 1.3));
	data->pic->y1 = (y / data->pic->zoom + data->pic->y1) - \
	(y / (data->pic->zoom * 1.3));
	data->pic->zoom *= 1.3;
	data->pic->it_max++;
}

void			mouse(int key, int x, int y, t_data *data)
{
	if (key == MOUSE_SCROLL_UP)
		zoom(x, y, data);
	if (key == MOUSE_SCROLL_DOWN)
		rev_zoom(x, y, data);
	if (key == MOUSE_LEFT_BUTTON)
	{
		if (data->pic->pause == 1)
			data->pic->pause = 0;
		else
			data->pic->pause = 1;
	}
	do_chosen_fractal(data);
}
