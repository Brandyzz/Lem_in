/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:10:59 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/21 15:11:01 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copyuntil(char *str, int c)
{
	char	*res;
	char	*symb;

	if (!str)
		return (NULL);
	symb = ft_strchr(str, c);
	if (!symb)
		return (NULL);
	res = ft_strnew(symb - str);
	if (!res)
		return (NULL);
	res = ft_strncpy(res, str, symb - str);
	return (res);
}
