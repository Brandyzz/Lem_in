/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_med.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:39:58 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:51:20 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	check_median(t_stack *stack, int med, int num, int flag)
{
	int	i;

	i = stack->point->top - num - 1;
	while (i < stack->point->top + 1)
	{
		if (stack->point->num[i] < med && flag == 0)
			return (1);
		if (stack->point->num[i] >= med && flag == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_med(t_stack *stack_a, int elem)
{
	int	i;
	int	j;
	int	nb;
	int	med;

	j = TOP_A - elem + 1;
	while (j < TOP_A + 1)
	{
		med = 0;
		i = TOP_A - elem + 1;
		nb = STK_A->num[j];
		while (i < TOP_A + 1)
		{
			if (nb != STK_A->num[i])
				(STK_A->num[i] > nb) ? med++ : med--;
			i++;
		}
		if (med == (elem % 2 == 0 ? -1 : 0))
			return (STK_A->num[j]);
		j++;
	}
	return (0);
}
