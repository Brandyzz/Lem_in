/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:19:47 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/20 20:35:55 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char			*strdest;
	const char		*strsource;

	strdest = dest;
	strsource = source;
	while (n > 0)
	{
		*strdest++ = *strsource++;
		n--;
	}
	return (dest);
}
