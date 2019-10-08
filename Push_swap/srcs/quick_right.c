/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:09 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:42:54 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_right_med(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	med;
	int	i;
	int	c;

	med = check_med(stack_b, nb);
	i = 0;
	c = 0;
	while (i <= nb && check_median(stack_b, med, nb, 1) != 0)
	{
		if (STK_B->nb[TOP_B] < med)
		{
			stack_b->rot(stack_b);
			cmd_add_left(stack_a, 3);
			c++;
		}
		if (STK_B->nb[TOP_B] >= med)
			stack_a->push(stack_b, stack_a, 0);
		i++;
	}
	while (c > 0 && (nb / 2 != TOP_B + 1))
	{
		stack_b->rev(stack_b);
		cmd_add_left(stack_a, 1);
		c--;
	}
}

int			quick_right(t_stack *stack_a, t_stack *stack_b, int nb)
{
	if (nb <= 2)
	{
		if (nb == 2 && STK_B->nb[TOP_B] < STK_B->nb[TOP_B - 1])
		{
			stack_b->swap(stack_b);
			cmd_add_left(stack_a, 2);
		}
		while (nb--)
			stack_a->push(stack_b, stack_a, 0);
		return (1);
	}
	quick_right_med(stack_a, stack_b, nb);
	quick_left(stack_a, stack_b, (nb / 2 + nb % 2));
	quick_right(stack_a, stack_b, nb / 2);
	return (0);
}
