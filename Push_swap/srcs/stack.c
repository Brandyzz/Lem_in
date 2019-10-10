/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:17 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/10 21:13:33 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(void *stack)
{
	int		tmp;
	t_stack	*s;

	s = (t_stack *)stack;
	if (s->stack->top > 0)
	{
		tmp = s->stack->nb[s->stack->top];
		s->stack->nb[s->stack->top] = s->stack->nb[s->stack->top - 1];
		s->stack->nb[s->stack->top - 1] = tmp;
	}
}

static void	stack_push(void *stack_a, void *stack_b, int sens)
{
	t_stack	*sa;
	t_stack	*sb;

	sa = (t_stack *)stack_a;
	sb = (t_stack *)stack_b;
	if (sa->stack->top != -1)
		sb->stack->nb[sb->stack->top++ + 1] = sa->stack->nb[sa->stack->top--];
	if (sens >= 0)
		(sens == 1) ? cmd_join(sa, "pb\n") : cmd_join(sb, "pa\n");
}

static void	stack_rotate(void *stack)
{
	t_stack	*this;
	int		tmp;
	int		i;

	this = (t_stack *)stack;
	if (this->stack->top > 0)
	{
		i = this->stack->top;
		tmp = this->stack->nb[this->stack->top];
		while (i > 0)
		{
			this->stack->nb[i] = this->stack->nb[i - 1];
			i--;
		}
		this->stack->nb[0] = tmp;
	}
}

static void	stack_reverse(void *stack)
{
	t_stack	*this;
	int		i;
	int		tmp;

	this = (t_stack *)stack;
	if (this->stack->nb != NULL)
	{
		if (this->stack->top > 0)
		{
			i = 0;
			tmp = this->stack->nb[0];
			while (i <= this->stack->top)
			{
				this->stack->nb[i] = this->stack->nb[i + 1];
				i++;
			}
			this->stack->nb[this->stack->top] = tmp;
		}
	}
}

t_stack		*stack_construct(char **param, int top)
{
	t_stack	*stack;

	if ((stack = (t_stack *)ft_memalloc(sizeof(t_stack))) != NULL)
	{
		stack->swap = &stack_swap;
		stack->push = &stack_push;
		stack->rot = &stack_rotate;
		stack->rev = &stack_reverse;
		stack->op = NULL;
		stack->stack = item_construct(param, top);
	}
	return (stack);
}
