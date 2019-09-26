/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:34:59 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 15:49:43 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    token_init(t_data *token)
{
    int i;

    i = 0;
    token->ants = 0;
    token->start = -1;
    token->end = -1;
    token->rooms = -1;
    token->tot = 0;
    token->ret = NULL;
    while (i < MAX)
    {
        token->output[i] = NULL;
        i++;
    }
    token->path = NULL;
}

int		get_id(char *name, t_data *data)
{
int	i;
	i = 0;
while (ft_strcmp(name, data->name[i]))
		i++;
return (i);
}

void	add_single(t_graph *graph, int i, int j)
{
	t_node	*tmp;
	t_node	*cop;
	cop = malloc(sizeof(t_node));
	cop->id = j;
	cop->next = NULL;
	cop->versh = 0;
if (graph->nodes[i])
	{
		tmp = graph->nodes[i];
while (tmp->next)
			tmp = tmp->next;
		tmp->next = cop;
	}
else
free(cop);
}
