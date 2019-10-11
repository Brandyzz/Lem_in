/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:47 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 18:53:56 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	*item_nb(char **av, int top)
{
	int	i;
	int	*nb;

	i = 0;
	if ((nb = (int *)ft_memalloc(sizeof(int) * top)) != NULL)
	{
		if (av != NULL)
		{
			while (av[i])
				nb[--top] = ft_atoi(av[i++]);
		}
		else
		{
			while (i < top - 1)
				nb[i++] = 0;
		}
	}
	return (nb);
}

t_point		*point_construct(char **av, int top)
{
	t_point	*new;

	if ((new = (t_point *)ft_memalloc(sizeof(t_point))) != NULL)
	{
		new->num = item_nb(av, top);
		new->top = (av == NULL ? -1 : --top);
	}
	return (new);
}
