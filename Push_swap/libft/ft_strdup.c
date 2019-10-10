/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:50 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/12 19:24:33 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *strr;

	strr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (strr == NULL)
		return (NULL);
	else
		return (ft_strcpy(strr, str));
}
