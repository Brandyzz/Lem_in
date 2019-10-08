/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:23:41 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/07 17:45:07 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void			fcalculating(t_data *data, t_pixels *pix, t_picture *pic)
{
	int			i;
	double		tmp;

	i = 0;
	pix->cx = pix->x / pic->zoom + pic->x1;
	pix->cy = pix->y / pic->zoom + pic->y1;
	pix->zx = 0;
	pix->zy = 0;
	while (pix->zx * pix->zx + pix->zy * pix->zy < 4 && i < pic->it_max)
	{
		tmp = pix->zx;
		pix->zx = pix->zx * pix->zx - pix->zy * pix->zy + pix->cx;
		pix->zy = 2 * tmp * pix->zy + pix->cy;
		i++;
	}
	add_color(data, pix, pic, i);
}

int					mandelbrot(t_data *data)
{
	char	*iterator;

	tmp_bits(data->tmp);
	data->pix->x = 0;
	while (data->pix->x < WIN_W)
	{
		data->pix->y = 0;
		while (data->pix->y < WIN_H)
		{
			fcalculating(data, data->pix, data->pic);
			data->pix->y++;
		}
		data->pix->x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
	mlx_string_put(data->mlx, data->window, 700, 20, 0xFFFFFF, "ITERATIONS :");
	if (!(iterator = ft_itoa(data->pic->it_max)))
		return (0);
	mlx_string_put(data->mlx, data->window, 900, 20, 0xFFFFFF, iterator);
	free(iterator);
	return (1);
}
