/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:37 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:05:15 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack->nb[stack->stack->top];
	while (i < stack->stack->top)
	{
		if (min > stack->stack->nb[i])
			min = stack->stack->nb[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack->nb[stack->stack->top];
	while (i < stack->stack->top)
	{
		if (max < stack->stack->nb[i])
			max = stack->stack->nb[i];
		i++;
	}
	return (max);
}

int	get_median(t_stack *stack)
{
	int i;
	int	j;
	int	nb;
	int	med;

	j = 0;
	while (j < stack->stack->top + 1)
	{
		med = 0;
		i = 0;
		nb = stack->stack->nb[j];
		while (i < stack->stack->top + 1)
		{
			if (nb != stack->stack->nb[i])
				(stack->stack->nb[i] > nb) ? med++ : med--;
			i++;
		}
		if (med == (stack->stack->top % 2 == 0 ? 0 : -1))
			return (stack->stack->nb[j]);
		j++;
	}
	return (0);
}

int	get_small(int i, int j, int k)
{
	if (i < j && i < k)
		return (1);
	if (j < i && j < k)
		return (2);
	return (3);
}

int	get_high(int i, int j, int k)
{
	if (i > j && i > k)
		return (1);
	if (j > i && j > k)
		return (2);
	return (3);
}
