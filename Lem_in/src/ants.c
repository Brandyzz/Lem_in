/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:50:00 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/07 13:51:32 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		has_reached_end(t_data *data, int *ants)
{
	int i;

	i = 0;
	while (i < data->ants)
	{
		if (ants[i++] < data->len_path)
			return (0);
	}
	return (1);
}

void	print_moves(t_data *data, int *ants, int *path_tab)
{
	int i;

	i = 0;
	while (i < data->ants)
	{
		if (ants[i] > -1 && ants[i] < data->len_path)
			ft_printf("L%d-%s ", i + 1, data->name[path_tab[ants[i]]]);
		i++;
	}
}

int		lstlen(t_path *path)
{
	t_path	*tmp;
	int		i;

	i = 0;
	tmp = path;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		*ft_lstinttab(t_path *path)
{
	t_path	*tmp;
	int		*ret;
	int		i;

	i = 0;
	tmp = path;
	ret = malloc(sizeof(int) * lstlen(path));
	while (tmp)
	{
		ret[i] = tmp->id;
		i++;
		tmp = tmp->next;
	}
	return (ret);
}

void	move_ants(t_data *data)
{
	int *ants;
	int i;
	int j;
	int *path_tab;

	if (!(ants = malloc(sizeof(int) * (data->ants))))
		return ;
	ft_memset(ants, -1, sizeof(int) * (data->ants));
	data->len_path = lstlen(data->path);
	path_tab = ft_lstinttab(data->path);
	j = 0;
	while (!has_reached_end(data, ants))
	{
		i = 0;
		while (i < j)
			ants[i++]++;
		print_moves(data, ants, path_tab);
		if (!has_reached_end(data, ants))
			ft_printf("\n");
		if (j <= data->ants)
			j++;
	}
	free(ants);
	free(path_tab);
}