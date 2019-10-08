/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:42 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:05:54 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	info(t_stack *stack_a, t_stack *stack_b, int ac)
{
	int i;

	i = 0;
	while (i < ac && stack_a != NULL)
	{
		if (i <= stack_a->stack->top)
			printf("A : index [%d] = {%d}\n", i, stack_a->stack->nb[i]);
		i++;
	}
	i = 0;
	while (i < ac && STK_A->nb[TOP_A] != STK_B->nb[TOP_A])
	{
		if (stack_b->stack->top >= 0 && i <= stack_b->stack->top)
			printf("B : index [%d] = {%d}\n", i, stack_b->stack->nb[i]);
		i++;
	}
	printf("top-a : %d\n", stack_a->stack->top);
	printf("top-b : %d\n", stack_b->stack->top);
}
