/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:16 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/10 21:14:14 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
void	cmd_add_right(t_stack *stack, int cmd)
{
	if (cmd % 3 == 1)
		cmd == 1 ? cmd_join(stack, "rra\n") :
			cmd_join(stack, "rrr\n");
	if (cmd % 3 == 2)
		cmd == 2 ? cmd_join(stack, "sa\n") : cmd_join(stack, "ss\n");
	if (cmd % 3 == 0)
		cmd == 3 ? cmd_join(stack, "ra\n") : cmd_join(stack, "rr\n");
}

void	cmd_add_left(t_stack *stack, int cmd)
{
	if (cmd % 3 == 1)
		cmd == 1 ? cmd_join(stack, "rrb\n") :
			cmd_join(stack, "rrr\n");
	if (cmd % 3 == 2)
		cmd == 2 ? cmd_join(stack, "sb\n") : cmd_join(stack, "ss\n");
	if (cmd % 3 == 0)
		cmd == 3 ? cmd_join(stack, "rb\n") : cmd_join(stack, "rr\n");
}

void	cmd_join(t_stack *stack, char *cmd)
{
	char	*tmp;

	if (stack->op == NULL)
		stack->op = ft_strdup(cmd);
	else
	{
		tmp = ft_strjoin(stack->op, cmd);
		free(stack->op);
		stack->op = tmp;
	}
}

void	cmd_print(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->op[i])
		i++;
	write(1, stack->op, i);
}
