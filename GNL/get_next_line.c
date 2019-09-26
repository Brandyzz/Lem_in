/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:01:23 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/02/28 19:38:02 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_newline(char **i, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (i[fd][len] != '\n' && i[fd][len] != '\0')
		len++;
	if (i[fd][len] == '\n')
	{
		*line = ft_strsub(i[fd], 0, len);
		tmp = ft_strdup(i[fd] + len + 1);
		free(i[fd]);
		i[fd] = tmp;
		if (i[fd][0] == '\0')
			ft_strdel(&i[fd]);
	}
	else if (i[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(i[fd]);
		ft_strdel(&i[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*i[255];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (i[fd] == NULL)
			i[fd] = ft_strnew(1);
		tmp = ft_strjoin(i[fd], buff);
		free(i[fd]);
		i[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (i[fd] == NULL || i[fd][0] == '\0'))
		return (0);
	return (ft_newline(i, line, fd, ret));
}

int main(int argc, char **argv)
{
	int i;
	int fd;
	char	*line;
		
	fd = 0;
	i = 1;
	line = NULL;
	/*if (argc >= 2)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while (get_next_line(fd, &line))
			{
				ft_putendl(line);
				free(line);
			}
			i++;
			close(fd);
		}
	}*/
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	get_next_line(fd1, &line);
	ft_putendl(line);
	get_next_line(fd2, &line);
	ft_putendl(line);
}