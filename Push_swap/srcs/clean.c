/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:12 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:03:55 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	clean_item(t_item **item)
{
	ft_memdel((void *)&(*item)->nb);
	ft_memdel((void *)&(*item));
	return (0);
}

void		clean_stack(t_stack **stack)
{
	t_item	**tmp;

	tmp = &(*stack)->stack;
	clean_item(tmp);
	ft_memdel((void *)&(*stack)->op);
	ft_memdel((void *)&(*stack));
}
