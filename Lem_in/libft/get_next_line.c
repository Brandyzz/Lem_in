/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:01:23 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/06 16:18:54 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
