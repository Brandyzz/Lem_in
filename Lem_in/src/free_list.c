/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:19:02 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 15:33:52 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    free_nodes(t_graph *graph, t_data *data)
{
    int     i;
    t_node  *tmp;
    t_node  *tmp2;

    i = 0;
    while (i < data->rooms)
    {
        if (graph->nodes[i])
        {
            tmp = graph->nodes[i];
            while (tmp)
            {
                tmp2 = tmp;
                free(tmp2);
                tmp = tmp->next;
            }
        }
        i++;
    }
}

void    free_path(t_data *data)
{
    t_path *tmp;
    t_path *tmp2;

    tmp = data->path;
    while (tmp)
    {
        tmp2 = tmp;
        free(tmp2);
        tmp = tmp->next;
    }
}

void    free_list(t_data *data, t_graph *graph, t_bfs *b)
{
    t_queue *tmp;
    t_queue *tmp2;

    tmp = b->queue;
    while (tmp)
    {
        tmp2 = tmp;
        free(tmp2);
        tmp = tmp->next;
    }
    free(b->output);
    free_nodes(graph, data);
    free_path(data);
}
