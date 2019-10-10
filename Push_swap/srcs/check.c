/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:39:58 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/10 20:17:01 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_median(t_stack *stack, int med, int nb, int sens)
{
	int	i;

	i = stack->stack->top - nb - 1;
	while (i < stack->stack->top + 1)
	{
		if (stack->stack->nb[i] < med && sens == 0)
			return (1);
		if (stack->stack->nb[i] >= med && sens == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_med(t_stack *stack_a, int nbelem)
{
	int	i;
	int	j;
	int	nb;
	int	med;

	j = TOP_A - nbelem + 1;
	while (j < TOP_A + 1)
	{
		med = 0;
		i = TOP_A - nbelem + 1;
		nb = STK_A->nb[j];
		while (i < TOP_A + 1)
		{
			if (nb != STK_A->nb[i])
				(STK_A->nb[i] > nb) ? med++ : med--;
			i++;
		}
		if (med == (nbelem % 2 == 0 ? -1 : 0))
			return (STK_A->nb[j]);
		j++;
	}
	return (0);
}
