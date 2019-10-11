/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:47 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:50:55 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	*item_nb(char **param, int top)
{
	int	i;
	int	*nb;

	i = 0;
	if ((nb = (int *)ft_memalloc(sizeof(int) * top)) != NULL)
	{
		if (param != NULL)
		{
			while (param[i])
				nb[--top] = ft_atoi(param[i++]);
		}
		else
		{
			while (i < top - 1)
				nb[i++] = 0;
		}
	}
	return (nb);
}

t_point		*point_construct(char **param, int top)
{
	t_point	*new;

	if ((new = (t_point *)ft_memalloc(sizeof(t_point))) != NULL)
	{
		new->num = item_nb(param, top);
		new->top = (param == NULL ? -1 : --top);
	}
	return (new);
}
