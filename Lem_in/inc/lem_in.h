/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:33:11 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 16:38:34 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft.h"
# define MAX 10000
# define NO_START "Error : no start or end"
# define NO_ANTS "Error : invalid ants format"
# define NO_ROOMS "Error : no rooms"
# define UNCORRECT_NAME "Error : Uncorrect name"
# define ERROR_ANTS 0
# define NO_FILE "Error : File doesn't exist or empty"

typedef struct		s_path
{
	int				ant;
	int				id;
	struct s_path	*next;
}					t_path;

typedef struct		s_data
{
	int				ants;
	int				tot;
	int				start;
	int				end;
	int				rooms;
	char			**ret;
	char			*name[MAX];
	t_path			*path;
	char			*output[MAX];
	int				len_path;
}					t_data;

typedef struct		s_node
{
	int				x;
	int				y;
	char			*name;
	int				id;
	int				versh;
	struct s_node	*next;
}					t_node;

typedef struct		s_queue
{
	int				id;
	int				parent;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_bfs
{
	t_queue			*queue;
	int				*output;
}					t_bfs;

typedef struct		s_graph
{
	t_node			*nodes[MAX];
	int				n_versh;
	int				n_edges;
}					t_graph;

void                token_init(t_data *token);
t_queue	            *ft_newlst(int id);
void                init_graph(t_graph *graph);
void                init_path(t_data *data, t_bfs *b);
void	            ft_push_back(t_queue **queue, int id, int parent);
t_queue	            *new_elem(int id, int parent);
void	            ft_push_front(t_path **path, int id);
t_path	            *new_path(int id);
void                free_list(t_data *data, t_graph *graph, t_bfs *b);
void                parse(t_graph *graph, t_data *data);
char	            *parse_room(t_data *data);
char	            **is_room(char *line);
void	            save_room(t_data *data, char **room, int *is_start, int *is_end);
void                parse_ant(t_data *data);
void                get_path(t_data *data, t_graph *graph, t_bfs *b);
void	            get_end(t_data *data, t_bfs *b, int id);
void	            get_output(t_data *data, t_graph *graph, t_bfs *b);
void	            add_to_node(t_node *tmp, t_bfs *b, int i);
int		            is_present(int id, int *output);
void                free_path(t_data *data);
void                free_nodes(t_graph *graph, t_data *data);
int		            is_comment(char *line);
int		            is_command(char *line);
int		            is_wrap_end(char *line, int *is_end);
int		            is_wrap_start(char *line, int *is_start);
int		            get_id(char *name, t_data *data);
void	            add_single(t_graph *graph, int i, int j);
void	            error_path(t_data *d, t_bfs *b);
void	            error_room(t_data *d);
void	            ft_fatal(int i);
int		            are_existing_rooms(t_data *d, char *e1, char *e2);
char	            **is_edge(t_data *data, char *line);
void	            save_edge(t_data *d, t_graph *g, char **edge);
void	            alone_line(t_data *d, t_graph *g, char *line);
void	            parse_edges(t_data *d, t_graph *g);
void	            check_double_edge(t_data *d, t_graph *g);
t_queue	            *del_first(t_queue *queue);


#endif