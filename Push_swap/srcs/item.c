/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:47 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/19 18:40:49 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_item		*item_construct(char **param, int top)
{
	t_item	*new;

	if ((new = (t_item *)ft_memalloc(sizeof(t_item))) != NULL)
	{
		new->nb = item_nb(param, top);
		new->top = (param == NULL ? -1 : --top);
	}
	return (new);
}
