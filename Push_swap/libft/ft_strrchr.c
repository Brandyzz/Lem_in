/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:11:06 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/12 19:55:21 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *lp;

	lp = NULL;
	while (*str != '\0')
	{
		if (*str == (char)ch)
			lp = (char*)str;
		str++;
	}
	if (*str == (char)ch)
		return ((char*)str);
	else
		return (lp);
}
