/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:37:06 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 14:48:11 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		are_existing_rooms(t_data *d, char *e1, char *e2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->name[i] && ft_strcmp(d->name[i], e1))
		i++;
	if (i > d->rooms)
		return (0);
	while (d->name[j] && ft_strcmp(d->name[j], e2))
		j++;
	if (j > d->rooms - 1)
		return (0);
	return (1);
}

void	ft_fatal(int i)
{
	if (i == 0)
		ft_putendl(NO_ANTS);
	else if (i == 1)
		ft_putendl(NO_START);
	else if (i == 2)
		ft_putendl(NO_ROOMS);
	else if (i == 3)
		ft_putendl(UNCORRECT_NAME);
	else if (i == 4)
		ft_putendl("Error : No or empty file");
	else if (i == 5)
		ft_putendl("Error : no path");
	else if (i == 7)
		ft_putendl("Error : invalid room");
	exit(0);
}

void	error_room(t_data *d)
{
	if (d->start == -1 || d->end == -1)
		ft_fatal(1);
	else if (d->rooms == 0)
		ft_fatal(2);
}

void	error_path(t_data *d, t_bfs *b)
{
	if (b->output[d->end] == -2)
		ft_fatal(5);
}