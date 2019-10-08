/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:30 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:02:18 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# define TOP_A stack_a->stack->top
# define TOP_B stack_b->stack->top
# define STK_A stack_a->stack
# define STK_B stack_b->stack

typedef struct	s_item
{
	int			*nb;
	int			top;
}				t_item;

typedef struct	s_stk
{
	void		(*swap)(void *);
	void		(*push)(void *, void *, int);
	void		(*rot)(void *);
	void		(*rev)(void *);
	char		*op;
	t_item		*stack;
}				t_stack;

int				order_reverse(t_stack *stack);
t_stack			*stack_construct(char **param, int top);
t_item			*item_construct(char **param, int top);
int				solve_order(t_stack *stack);
void			solve_order_reverse(t_stack *stack_a, t_stack *stack_b);
void			solve_stack(t_stack *stack_a, t_stack *stack_b);
int				quick_right(t_stack *stack_a, t_stack *stack_b, int nb);
int				quick_left(t_stack *stack_a, t_stack *stack_b, int nb);
int				get_min(t_stack *stack);
int				get_max(t_stack *stack);
int				get_median(t_stack *stack);
int				get_high(int i, int j, int k);
int				get_small(int i, int j, int k);
int				check_median(t_stack *stack, int med, int nb, int sens);
int				check_med(t_stack *stack_a, int nbelem);
void			cmd_add_right(t_stack *stack, int cmd);
void			cmd_add_left(t_stack *stack, int cmd);
void			cmd_join(char **op, char *cmd);
void			cmd_print(t_stack *stack);
int				error_nbr(int ac, char **av);
int				error_instr(char *instr);
int				error_case(char **av);
void			clean_stack(t_stack **stack);

#endif
