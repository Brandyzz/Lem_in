/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:52:03 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/05 19:24:49 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

static void			fcalculating(t_data *data, t_pixels *pix, t_picture *pic)
{
	int		i;
	double	tmp;

	i = 0;
	pix->zx = pix->x / pic->zoom + pic->x1;
	pix->zy = pix->y / pic->zoom + pic->y1;
	while (pix->zx * pix->zx + pix->zy * pix->zy < 4 && i < pic->it_max)
	{
		tmp = pix->zx;
		pix->zx = pix->zx * pix->zx - pix->zy * pix->zy + pix->cx;
		pix->zy = 2 * pix->zy * tmp + pix->cy;
		i++;
	}
	add_color(data, pix, pic, i);
}

int					julia(t_data *data)
{
	char	*iterations;

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
	mlx_string_put(data->mlx, data->window, 700, 20, 0xFFFFFF, "ITERATIONS : ");
	if (!(iterations = ft_itoa(data->pic->it_max)))
		return (0);
	mlx_string_put(data->mlx, data->window, 900, 20, 0xFFFFFF, iterations);
	free(iterations);
	return (1);
}
