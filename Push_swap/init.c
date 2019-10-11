/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:17 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 18:53:18 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static void	stack_swap(void *stack)
{
	int		tmp;
	t_stack	*s;

	s = (t_stack *)stack;
	if (s->point->top > 0)
	{
		tmp = s->point->num[s->point->top];
		s->point->num[s->point->top] = s->point->num[s->point->top - 1];
		s->point->num[s->point->top - 1] = tmp;
	}
}

static void	stack_push(void *stack_a, void *stack_b, int sens)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = (t_stack *)stack_a;
	stk_b = (t_stack *)stack_b;
	if (stk_a->point->top != -1)
		stk_b->point->num[stk_b->point->top++ + 1] =
		stk_a->point->num[stk_a->point->top--];
	if (sens >= 0)
		(sens == 1) ? op_join(stk_a, "pb\n") : op_join(stk_b, "pa\n");
}

static void	stack_rotate(void *stack)
{
	t_stack	*stk;
	int		tmp;
	int		i;

	stk = (t_stack *)stack;
	if (stk->point->top > 0)
	{
		i = stk->point->top;
		tmp = stk->point->num[stk->point->top];
		while (i > 0)
		{
			stk->point->num[i] = stk->point->num[i - 1];
			i--;
		}
		stk->point->num[0] = tmp;
	}
}

static void	stack_reverse(void *stack)
{
	t_stack	*stk;
	int		i;
	int		tmp;

	stk = (t_stack *)stack;
	if (stk->point->num != NULL)
	{
		if (stk->point->top > 0)
		{
			i = 0;
			tmp = stk->point->num[0];
			while (i <= stk->point->top)
			{
				stk->point->num[i] = stk->point->num[i + 1];
				i++;
			}
			stk->point->num[stk->point->top] = tmp;
		}
	}
}

t_stack		*stack_construct(char **av, int top)
{
	t_stack	*stack;

	if ((stack = (t_stack *)ft_memalloc(sizeof(t_stack))) != NULL)
	{
		stack->swap = &stack_swap;
		stack->push = &stack_push;
		stack->rot = &stack_rotate;
		stack->rev = &stack_reverse;
		stack->op = NULL;
		stack->point = point_construct(av, top);
	}
	return (stack);
}
