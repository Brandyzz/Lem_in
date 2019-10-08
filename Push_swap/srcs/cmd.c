/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:40:16 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:04:07 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_add_right(t_stack *stack, int cmd)
{
	if (cmd % 3 == 1)
		cmd == 1 ? cmd_join(&stack->op, "rra\n") :
			cmd_join(&stack->op, "rrr\n");
	if (cmd % 3 == 2)
		cmd == 2 ? cmd_join(&stack->op, "sa\n") : cmd_join(&stack->op, "ss\n");
	if (cmd % 3 == 0)
		cmd == 3 ? cmd_join(&stack->op, "ra\n") : cmd_join(&stack->op, "rr\n");
}

void	cmd_add_left(t_stack *stack, int cmd)
{
	if (cmd % 3 == 1)
		cmd == 1 ? cmd_join(&stack->op, "rrb\n") :
			cmd_join(&stack->op, "rrr\n");
	if (cmd % 3 == 2)
		cmd == 2 ? cmd_join(&stack->op, "sb\n") : cmd_join(&stack->op, "ss\n");
	if (cmd % 3 == 0)
		cmd == 3 ? cmd_join(&stack->op, "rb\n") : cmd_join(&stack->op, "rr\n");
}

void	cmd_join(char **op, char *cmd)
{
	char	*tmp;

	if (*op == NULL)
		*op = ft_strdup(cmd);
	else
	{
		tmp = *op;
		*op = ft_strjoin(tmp, cmd);
		ft_memdel((void *)&tmp);
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
