/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:16 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 17:50:32 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	add_right(t_stack *stack, int op)
{
	if (op % 3 == 1)
		op == 1 ? op_join(stack, "rra\n") :
			op_join(stack, "rrr\n");
	if (op % 3 == 2)
		op == 2 ? op_join(stack, "sa\n") : op_join(stack, "ss\n");
	if (op % 3 == 0)
		op == 3 ? op_join(stack, "ra\n") : op_join(stack, "rr\n");
}

void	add_left(t_stack *stack, int op)
{
	if (op % 3 == 1)
		op == 1 ? op_join(stack, "rrb\n") :
			op_join(stack, "rrr\n");
	if (op % 3 == 2)
		op == 2 ? op_join(stack, "sb\n") : op_join(stack, "ss\n");
	if (op % 3 == 0)
		op == 3 ? op_join(stack, "rb\n") : op_join(stack, "rr\n");
}

void	op_join(t_stack *stack, char *op)
{
	char	*tmp;

	if (stack->op == NULL)
		stack->op = ft_strdup(op);
	else
	{
		tmp = ft_strjoin(stack->op, op);
		free(stack->op);
		stack->op = tmp;
	}
}

void	op_print(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->op[i])
		i++;
	write(1, stack->op, i);
}
