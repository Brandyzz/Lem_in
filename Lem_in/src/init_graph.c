/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:04:15 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 14:31:50 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*del_first(t_queue *queue)
{
	t_queue	*tmp;

	tmp = queue;
	if (queue->next)
		queue = queue->next;
	else
		queue = NULL;
	free(tmp);
	return (queue);
}

void init_path(t_data *data, t_bfs *b)
{
    int i;

    i = 0;
    b->output = (int *)malloc(sizeof(int) * data->rooms);
    while (i < data->rooms)
    {
        b->output[i] = -3;
        i++;
    }
    b->output[data->start] = -1;
    b->output[data->end] = -2;
    b->queue = ft_newlst(data->start);
}

void    init_graph(t_graph *graph)
{
    int i;

    i = 0;
    graph->n_versh = 0;
    graph->n_edges = 0;
    while (i < MAX + 1)
    {
        graph->nodes[i] = NULL;
        i++;
    }
}