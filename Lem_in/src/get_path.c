/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:16:57 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 15:51:29 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_present(int id, int *output)
{
	if (output[id] >= 0)
		return (1);
	return (0);
}

void	add_to_node(t_node *tmp, t_bfs *b, int i)
{
	int	id;
	int	parent;

	while (tmp)
	{
		if (!is_present(tmp->id, b->output))
		{
			id = tmp->id;
			parent = i;
			ft_push_back(&b->queue, id, parent);
			tmp->versh = 1;
		}
		tmp = tmp->next;
	}
}

void	get_output(t_data *data, t_graph *graph, t_bfs *b)
{
	t_node	*tmp;
	int		i;

	init_path(data, b);
	while (b->queue)
	{
		i = b->queue->id;
		if (b->output[i] < 0 && b->output[i] != -1)
			b->output[i] = b->queue->parent;
		b->queue = del_first(b->queue);
		if (graph->nodes[i])
		{
			tmp = graph->nodes[i];
			add_to_node(tmp, b, i);
		}
	}
}

void	get_end(t_data *data, t_bfs *b, int id)
{
	if (b->output[id] == -1)
		return ;
	if (!data->path)
		data->path = new_path(id);
	else
		ft_push_front(&data->path, id);
	get_end(data, b, b->output[id]);
}

void	get_path(t_data *data, t_graph *graph, t_bfs *b)
{
	get_output(data, graph, b);
	if (b->output[data->end] == -2)
	{
		ft_putendl("Error : no path");
		exit(0);
	}
	get_end(data, b, data->end);
}
