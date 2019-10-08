/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:41:35 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/07 16:12:10 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			more_colors(t_data *data, t_pixels *pix, int i)
{
	if (i % 16 == 7)
		data->tmp[pix->y * WIN_W + pix->x] = 0x397DD1;
	else if (i % 16 == 8)
		data->tmp[pix->y * WIN_W + pix->x] = 0x86B5E5;
	else if (i % 16 == 9)
		data->tmp[pix->y * WIN_W + pix->x] = 0xD3ECF8;
	else if (i % 16 == 10)
		data->tmp[pix->y * WIN_W + pix->x] = 0xF1E9BF;
	else if (i % 16 == 11)
		data->tmp[pix->y * WIN_W + pix->x] = 0xF8C95F;
	else if (i % 16 == 12)
		data->tmp[pix->y * WIN_W + pix->x] = 0xFFAA00;
	else if (i % 16 == 13)
		data->tmp[pix->y * WIN_W + pix->x] = 0xCC8000;
	else if (i % 16 == 14)
		data->tmp[pix->y * WIN_W + pix->x] = 0x995700;
	else if (i % 16 == 15)
		data->tmp[pix->y * WIN_W + pix->x] = 0x971616;
}

void			add_color(t_data *data, t_pixels *pix, t_picture *pic, int i)
{
	if (i == pic->it_max)
		data->tmp[pix->y * WIN_W + pix->x] = 0;
	else if (i % 16 == 0)
		data->tmp[pix->y * WIN_W + pix->x] = 0;
	else if (i % 16 == 1)
		data->tmp[pix->y * WIN_W + pix->x] = 0;
	else if (i % 16 == 2)
		data->tmp[pix->y * WIN_W + pix->x] = 0x9012F;
	else if (i % 16 == 3)
		data->tmp[pix->y * WIN_W + pix->x] = 0x40449;
	else if (i % 16 == 4)
		data->tmp[pix->y * WIN_W + pix->x] = 0x764;
	else if (i % 16 == 5)
		data->tmp[pix->y * WIN_W + pix->x] = 0xC2C8A;
	else if (i % 16 == 6)
		data->tmp[pix->y * WIN_W + pix->x] = 0x1852B1;
	else
		more_colors(data, pix, i);
}
