/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:37 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:50:59 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	get_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->point->num[stack->point->top];
	while (i < stack->point->top)
	{
		if (min > stack->point->num[i])
			min = stack->point->num[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->point->num[stack->point->top];
	while (i < stack->point->top)
	{
		if (max < stack->point->num[i])
			max = stack->point->num[i];
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
	while (j < stack->point->top + 1)
	{
		med = 0;
		i = 0;
		nb = stack->point->num[j];
		while (i < stack->point->top + 1)
		{
			if (nb != stack->point->num[i])
				(stack->point->num[i] > nb) ? med++ : med--;
			i++;
		}
		if (med == (stack->point->top % 2 == 0 ? 0 : -1))
			return (stack->point->num[j]);
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
