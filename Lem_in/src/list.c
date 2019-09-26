/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:14:04 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 14:17:42 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*ft_newlst(int id)
{
	t_queue *queue;

	queue = (t_queue*)malloc(sizeof(t_queue));
	queue->id = id;
	queue->parent = -2;
	queue->next = NULL;
	return (queue);
}

t_path	*new_path(int id)
{
	t_path *path;

	path = malloc(sizeof(t_path));
	path->id = id;
	path->ant = 0;
	path->next = NULL;
	return (path);
}

void	ft_push_front(t_path **path, int id)
{
	t_path *tmp;

	if (*path)
	{
		tmp = new_path(id);
		tmp->next = *path;
		*path = tmp;
	}
	else
		*path = new_path(id);
}

t_queue	*new_elem(int id, int parent)
{
	t_queue *new_elem;

	new_elem = malloc(sizeof(*new_elem));
	new_elem->next = NULL;
	new_elem->id = id;
	new_elem->parent = parent;
	return (new_elem);
}

void	ft_push_back(t_queue **queue, int id, int parent)
{
	t_queue *tmp;

	tmp = *queue;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem(id, parent);
	}
	else
		*queue = new_elem(id, parent);
}
