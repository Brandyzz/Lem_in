/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:12 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:51:04 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void		free_all(t_stack *stack)
{
	if (stack->point->num)
	{
		free(stack->point->num);
		stack->point->num = NULL;
	}
	if (stack->point)
	{
		free(stack->point);
		stack->point = NULL;
	}
	if (stack->op)
	{
		free(stack->op);
		stack->op = NULL;
	}
	if (stack)
	{
		free(stack);
		stack = NULL;
	}
}
