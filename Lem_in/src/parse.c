/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:23:44 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 14:49:10 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    parse_ant(t_data *data)
{
    char    *line;
    int     i;

    i = 0;
    if (!get_next_line(0, &line))
    {
        ft_putendl(NO_FILE);
        return ;
    }
    data->ants = ft_atoi(line);
    while (line[i])
    {
        if (ft_isdigit_str(line) || data->ants <= 0)
            ft_putendl(ERROR_ANTS);
        i++;
    }
    ft_putendl(line);
    ft_strdel(&line);
}

void	save_room(t_data *data, char **room, int *is_start, int *is_end)
{
	data->name[data->rooms] = ft_strdup(room[0]);
	ft_strsplitdel(room);
	if (*is_start == 1)
	{
		data->start = data->rooms;
		*is_start = 0;
	}
	if (*is_end == 1)
	{
		data->end = data->rooms;
		*is_end = 0;
	}
	data->rooms++;
}

char	**is_room(char *line)
{
	char	**ret;
	int		len;

	len = 0;
	ret = ft_split_whitespaces(line);
	while (ret[len] != NULL)
		len++;
	if (len != 3)
	{
		ft_strsplitdel(ret);
		return (NULL);
	}
	if (ret[0][0] == 'L' || ret[0][0] == '#' || !ft_isdigit_str(ret[1])
						|| !ft_isdigit_str(ret[2]))
	{
		ft_strsplitdel(ret);
		ft_putstr("Error : Invalid room");
	}
	return (ret);
}

char	*parse_room(t_data *data)
{
	char	*line;
	char	**room;
	int		is_start;
	int		is_end;

	is_start = 0;
	is_end = 0;
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))
	{
		ft_putendl(line);
		if (is_wrap_start(line, &is_start) || is_wrap_end(line, &is_end))
			;
		else if ((room = is_room(line)))
			save_room(data, room, &is_start, &is_end);
		ft_strdel(&line);
	}
	return (line);
}

void    parse(t_graph *graph, t_data *data)
{
    char *line;
    parse_ant(data);
    line = parse_room(data);
	error_room(data);
	alone_line(data, graph, line);
	parse_edges(data, graph);
	check_double_edge(data, graph);
}