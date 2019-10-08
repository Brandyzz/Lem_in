/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:37:26 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/21 15:09:35 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	vargs;
	int		i;
	int		ret;
	int		j;

	i = -1;
	ret = 0;
	va_start(vargs, form);
	while (form[++i])
	{
		if (form[i] == '%')
			ret += do_tok(form + i + 1, vargs, &i);
		else
		{
			j = 0;
			j += ft_putstr_until((char *)form + i, '%');
			ret += j;
			i += j - 1;
		}
	}
	va_end(vargs);
	return (ret);
}
