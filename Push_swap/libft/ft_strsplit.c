/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:58:01 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:58:03 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countstr(char const *s, char c)
{
	size_t		count;
	size_t		word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (word == 1 && *s == c)
			word = 0;
		if (word == 0 && *s != c)
		{
			word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	wordlen(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**str;
	size_t			n;
	unsigned int	i;

	n = countstr(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	i = 0;
	while (n--)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_strsub(s, 0, wordlen(s, c));
		if (!str[i])
			return (NULL);
		s += wordlen(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
