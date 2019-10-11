/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:03 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:55:20 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static void	do_more_str(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strlen(str) == 2)
	{
		if (str[1] == 'r')
		{
			stack_b->rot(stack_b);
			stack_a->rot(stack_a);
		}
		else
			str[1] == 'b' ? stack_b->rot(stack_b) : stack_a->rot(stack_a);
	}
	else
	{
		if (str[2] == 'r')
		{
			stack_b->rev(stack_b);
			stack_a->rev(stack_a);
		}
		else
			str[2] == 'b' ? stack_b->rev(stack_b) : stack_a->rev(stack_a);
	}
}

static void	do_str(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str[0] == 'p')
		str[1] == 'b' ? stack_a->push(stack_a, stack_b, -1) :
		stack_a->push(stack_b, stack_a, -1);
	if (str[0] == 's')
	{
		if (str[1] == 's')
		{
			stack_b->swap(stack_b);
			stack_a->swap(stack_a);
		}
		else
			str[1] == 'b' ? stack_b->swap(stack_b) : stack_a->swap(stack_a);
	}
	if (str[0] == 'r')
		do_more_str(str, stack_a, stack_b);
}

static int	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*buff;

	buff = NULL;
	while (get_next_line(0, &buff) > 0)
	{
		if (error_str(buff) == 0)
		{
			free(buff);
			return (0);
		}
		else
			do_str(buff, stack_a, stack_b);
		free(buff);
	}
	if (TOP_B == -1)
		(solve_order(stack_a) == 1 ? write(1, "OK\n", 3) : write(1, "KO\n", 3));
	else
		write(1, "KO\n", 3);
	return (1);
}

int			main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ac--;
	av++;
	if (ac == 0 || error_nbr(ac, av) != 0)
		return (0);
	else
	{
		stack_a = stack_construct(av, ac);
		stack_b = stack_construct(NULL, ac);
		checker(stack_a, stack_b);
		free_all(stack_a);
		free_all(stack_b);
	}
	return (0);
}
