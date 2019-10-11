/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:55 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:57:45 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int		solve_order(t_stack *stack)
{
	int	i;

	i = stack->point->top;
	while (i > 0)
	{
		if (stack->point->num[i] > stack->point->num[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int		order_reverse(t_stack *stack)
{
	int	i;

	i = stack->point->top;
	while (i > 0)
	{
		if (stack->point->num[i] < stack->point->num[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	solve_reverse(t_stack *stack_a, t_stack *stack_b)
{
	if (order_reverse(stack_a) == 1 && solve_order(stack_a) != 1)
	{
		if (stack_a->point->top == 1)
		{
			stack_a->swap(stack_a);
			op_join(stack_a, "sa\n");
		}
		else
		{
			while (stack_a->point->top > 2)
			{
				stack_a->rev(stack_a);
				op_join(stack_a, "rra\n");
				stack_a->push(stack_a, stack_b, 1);
			}
			stack_a->swap(stack_a);
			stack_a->rev(stack_a);
			op_join(stack_a, "sa\nrra\n");
			while (stack_b->point->top != -1)
				stack_a->push(stack_b, stack_a, 0);
		}
	}
}
