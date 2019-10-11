/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:41:30 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/10/11 18:54:07 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# define TOP_A stack_a->point->top
# define TOP_B stack_b->point->top
# define STK_A stack_a->point
# define STK_B stack_b->point

typedef struct	s_point
{
	int			top;
	int			*num;
}				t_point;

typedef struct	s_stack
{
	void		(*swap)(void *);
	void		(*push)(void *, void *, int);
	void		(*rot)(void *);
	void		(*rev)(void *);
	char		*op;
	t_point		*point;
	int			vis;
}				t_stack;

int				order_reverse(t_stack *stack);
t_stack			*stack_construct(char **av, int top);
t_point			*point_construct(char **av, int top);
int				solve_order(t_stack *stack);
void			solve_reverse(t_stack *stack_a, t_stack *stack_b);
void			solve_stack(t_stack *stack_a, t_stack *stack_b);
int				right(t_stack *stack_a, t_stack *stack_b, int nb);
int				left(t_stack *stack_a, t_stack *stack_b, int nb);
int				get_min(t_stack *stack);
int				get_max(t_stack *stack);
int				get_median(t_stack *stack);
int				get_high(int i, int j, int k);
int				get_small(int i, int j, int k);
int				check_median(t_stack *stack, int med, int nb, int sens);
int				check_med(t_stack *stack_a, int nbelem);
void			add_right(t_stack *stack, int op);
void			add_left(t_stack *stack, int op);
void			op_join(t_stack *stack, char *op);
void			op_print(t_stack *stack);
int				error_nbr(int ac, char **av);
int				error_str(char *instr);
int				error_case(char **av);
void			free_all(t_stack *stack);

#endif
