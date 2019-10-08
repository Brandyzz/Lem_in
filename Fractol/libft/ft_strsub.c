/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:43:42 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/20 20:43:24 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*r;
	size_t		i;

	if (!s || !(r = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[i])
		r[i++] = s[start++];
	r[i] = '\0';
	return (r);
}
