/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:05 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:42:02 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_left_med(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	i;
	int	c;
	int	med;

	med = check_med(stack_a, nb);
	i = 0;
	c = 0;
	while (i <= nb && check_median(stack_a, med, nb, 0) != 0)
	{
		if (STK_A->nb[TOP_A] >= med)
		{
			stack_a->rot(stack_a);
			cmd_add_right(stack_a, 3);
			c++;
		}
		else
			stack_a->push(stack_a, stack_b, 1);
		i++;
	}
	while (c > 0 && (nb / 2 + nb % 2) != TOP_A + 1)
	{
		stack_a->rev(stack_a);
		cmd_add_right(stack_a, 1);
		c--;
	}
}

int			quick_left(t_stack *stack_a, t_stack *stack_b, int nb)
{
	if (nb <= 2)
	{
		if (nb == 2 && STK_A->nb[TOP_A] > STK_A->nb[TOP_A - 1])
		{
			stack_a->swap(stack_a);
			cmd_add_right(stack_a, 2);
		}
		return (1);
	}
	quick_left_med(stack_a, stack_b, nb);
	quick_left(stack_a, stack_b, nb / 2 + nb % 2);
	quick_right(stack_a, stack_b, nb / 2);
	return (0);
}
