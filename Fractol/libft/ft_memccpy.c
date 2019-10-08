/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:50:24 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/20 20:10:21 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char		*csrc;
	unsigned char		*cdst;
	size_t				i;

	csrc = (unsigned char *)source;
	cdst = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (cdst[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
