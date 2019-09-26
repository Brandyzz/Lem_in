/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:55:53 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:55:55 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void *dst;

	if (src == NULL || n == 0)
		return (NULL);
	if (!(dst = ft_memalloc(n)))
		return (NULL);
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
