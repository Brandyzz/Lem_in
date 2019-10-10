/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:12 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/10 20:58:10 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		clean_stack(t_stack *stack)
{
	if (stack->stack->nb)
	{
		free(stack->stack->nb);
		stack->stack->nb = NULL;
	}
	if (stack->stack)
	{
		free(stack->stack);
		stack->stack = NULL;
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
