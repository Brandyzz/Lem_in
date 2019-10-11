/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:02:16 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 18:19:51 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int i;

	i = 0;
	if (STK_A->num > STK_B->num)
		max = STK_A->num;
	else
		max = STK_B->num;
	ft_printf("Stack A: \t\tStack B: \n");
	while (i < max)
	{
		if (i < STK_A->num && i < STK_B->num)
			printf("%d\t\t\t%d\n", STK_A->num[i], STK_B->num[i]);
		if (i < STK_A->num && !(i < STK_B->num))
			ft_printf("%d\n", STK_A->num[i]);
		if (!(i < STK_A->num) && i < STK_B->num)
			ft_printf("%d\n", STK_B->num[i]);
		i++;
	}
}

static void	print_stack(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(stack[i]);
		i++;
	}
}

void		visualize(t_stack *stack)
{
    t_stack *stack_a;
    t_stack *stack_b;

	if (STK_A->num && !STK_B->num)
	{
		ft_printf("Stack A: \n");
		print_stack(STK_A, STK_A->num);
		ft_printf("-----------\n");
	}
	if (!STK_A->num && STK_B->num)
	{
		ft_putstr("Stack B: \n");
		print_stack(STK_A, STK_A->num);
		ft_putstr("-----------\n");
	}
	if (STK_A->num && STK_B->num)
	{
		print_stacks(STK_A, STK_A->num);
		ft_putstr("-----------\t\t-----------\n");
	}
}