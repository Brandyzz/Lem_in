/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:04:07 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/12 19:18:16 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char *strarr;

	strarr = (unsigned char*)arr;
	while (n > 0)
	{
		if (*strarr == (unsigned char)c)
			return ((void *)strarr);
		strarr++;
		n--;
	}
	return (NULL);
}
