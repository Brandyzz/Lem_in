/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:00 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:55:49 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static void	push_swap(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_construct(av, ac);
	stack_b = stack_construct(NULL, ac);
	if (stack_a->point->top > 0 && solve_order(stack_a) != 1)
	{
		(ac <= 5 ? solve_stack(stack_a, stack_b) :
		left(stack_a, stack_b, TOP_A + 1));
		op_print(stack_a);
	}
	free_all(stack_a);
	free_all(stack_b);
}

int			main(int ac, char **av)
{
	av++;
	ac--;
	if (error_nbr(ac, av) != 0)
		return (0);
	else
		push_swap(ac, av);
	return (0);
}
