/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:19:22 by jjory-ca          #+#    #+#             */
/*   Updated: 2018/12/20 20:04:27 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ');
}

static int		ft_overlong(long long int r, int minus)
{
	if (r < 0 && minus == 1)
		return (-1);
	else if (r < 0 && minus == -1)
		return (0);
	return (1);
}

int				ft_atoi(const char *str)
{
	long long int	r;
	int				minus;

	r = 0;
	minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - '0';
		str++;
		if (ft_overlong(r, minus) <= 0)
			return (ft_overlong(r, minus));
	}
	return (r * minus);
}
