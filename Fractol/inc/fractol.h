/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:52:02 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/07 16:55:41 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "keycodes.h"
# include <pthread.h>
# include "../libft/libft.h"

# define WIN_H 1600
# define WIN_W 1600

typedef struct		s_pixels
{
	int				x;
	int				y;
	int				y_max;
	double			cx;
	double			cy;
	double			zx;
	double			zy;
}					t_pixels;

typedef struct		s_picture
{
	int				it_max;
	int				n;
	double			zoom;
	double			x1;
	double			y1;
	int				pause;
}					t_picture;

typedef struct		s_data
{
	t_pixels		*pix;
	t_picture		*pic;
	void			*mlx;
	void			*window;
	void			*image;
	int				bpp;
	int				line;
	int				endian;
	int				fractal;
	unsigned int	*tmp;
}					t_data;

int					close_window(t_data *data);
t_data				*init_data(void);
void				keys(int key, t_data *data);
void				choice_of_fractal(char *av, t_data *data);
int					errors(int reason);
void				tmp_bits(unsigned int *tmp);
int					mandelbrot(t_data *data);
int					do_chosen_fractal(t_data *data);
void				add_color(t_data *data, t_pixels *pix,\
						t_picture *pic, int i);
void				mouse(int key, int x, int y, t_data *data);
void				more_colors(t_data *data, t_pixels *pix, int i);
int					julia(t_data *data);
int					dancing_julia(int x, int y, void *data);
int					multibrot(t_data *data);
int					burningship(t_data *data);

#endif
