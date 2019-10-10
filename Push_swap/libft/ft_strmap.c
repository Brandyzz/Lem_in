/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:23:41 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/20 20:16:38 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*r;
	size_t		l;
	size_t		i;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	if (!(r = (char *)malloc(l + 1)))
		return (NULL);
	i = 0;
	while (i < l)
	{
		r[i] = f(s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
