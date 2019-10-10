/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:12 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/10 21:13:18 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_secondary(t_stack *stack_a, t_stack *stack_b, int cmd)
{
	if (cmd == 1 && (stack_b->stack->nb[0] >
				stack_b->stack->nb[stack_b->stack->top]))
	{
		stack_b->rev(stack_b);
		cmd += 3;
	}
	if (cmd == 2 &&
			(stack_b->stack->nb[stack_b->stack->top - 1] >
			stack_b->stack->nb[stack_b->stack->top]))
	{
		stack_b->swap(stack_b);
		cmd += 3;
	}
	if (cmd == 3 && (stack_b->stack->nb[0] < stack_b->stack->nb[stack_b->stack->top]
			|| (stack_b->stack->nb[stack_b->stack->top - 1] >
			stack_b->stack->nb[stack_b->stack->top]
			&& stack_b->stack->nb[0] < stack_b->stack->nb[stack_b->stack->top - 1])))
	{
		stack_b->rot(stack_b);
		cmd += 3;
	}
	cmd_add_right(stack_a, cmd);
}

static void	solve_soft(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = get_min(stack_a);
	while (solve_order(stack_a) != 1
			&& (min == stack_a->stack->nb[0] ||
				min == stack_a->stack->nb[stack_a->stack->top] ||
				min == stack_a->stack->nb[stack_a->stack->top - 1]))
	{
		if (min == stack_a->stack->nb[stack_a->stack->top])
			stack_a->push(stack_a, stack_b, 1);
		if (min == stack_a->stack->nb[0])
		{
			stack_a->rev(stack_a);
			solve_secondary(stack_a, stack_b, 1);
		}
		if (min == stack_a->stack->nb[stack_a->stack->top - 1])
		{
			stack_a->swap(stack_a);
			solve_secondary(stack_a, stack_b, 2);
		}
		min = get_min(stack_a);
	}
}

static void	solve_end(t_stack *stack_a, t_stack *stack_b)
{
	if (solve_order(stack_b))
	{
		while (stack_b->stack->top != -1)
			stack_a->push(stack_b, stack_a, 0);
	}
	else
	{
		while (stack_b->stack->top != -1)
		{
			if (get_max(stack_b) == stack_b->stack->nb[stack_b->stack->top])
				stack_a->push(stack_b, stack_a, 0);
			else if (get_max(stack_b) == stack_b->stack->nb[stack_b->stack->top - 1])
			{
				stack_b->swap(stack_b);
				cmd_join(stack_a, "sb\n");
			}
			else
			{
				stack_b->rot(stack_b);
				cmd_join(stack_a, "rb\n");
			}
		}
	}
}

static void	solve_pivot(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack->nb[stack_a->stack->top] > stack_a->stack->nb[stack_a->stack->top / 2])
	{
		if (stack_a->stack->nb[0] < stack_a->stack->nb[stack_a->stack->top / 2])
		{
			stack_a->rev(stack_a);
			solve_secondary(stack_a, stack_b, 1);
		}
		else if (stack_a->stack->nb[stack_a->stack->top - 1] <
				stack_a->stack->nb[stack_a->stack->top / 2])
		{
			stack_a->swap(stack_a);
			solve_secondary(stack_a, stack_b, 2);
		}
		else
		{
			stack_a->rot(stack_a);
			solve_secondary(stack_a, stack_b, 3);
		}
	}
	else
		(solve_order(stack_a) == 1) ? solve_order(stack_b) :
		stack_a->push(stack_a, stack_b, 1);
}

void		solve_stack(t_stack *stack_a, t_stack *stack_b)
{
	solve_order_reverse(stack_a, stack_b);
	while (solve_order(stack_a) != 1)
	{
		solve_soft(stack_a, stack_b);
		solve_pivot(stack_a, stack_b);
	}
	solve_end(stack_a, stack_b);
}
