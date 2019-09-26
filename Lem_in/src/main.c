/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:55:10 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 15:22:42 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main (void)
{
    t_data  token;
    t_graph graph;
    t_bfs   bfs;

    token_init(&token);
    init_graph(&graph);
    parse(&graph, &token);
    get_path(&token, &graph, &bfs);
    
    return(0);
}