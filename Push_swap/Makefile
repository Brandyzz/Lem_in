# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 09:32:29 by nhuber            #+#    #+#              #
#    Updated: 2019/08/20 16:51:48 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME2 = checker
H_DIR = inc
F_DIR = srcs
L_DIR = libft
FILES = $(F_DIR)/cmd.c \
		$(F_DIR)/check.c \
		$(F_DIR)/error.c \
		$(F_DIR)/error2.c \
		$(F_DIR)/get.c \
		$(F_DIR)/item.c \
		$(F_DIR)/quick_left.c \
		$(F_DIR)/quick_right.c \
		$(F_DIR)/soft_solve.c \
		$(F_DIR)/stack.c \
		$(F_DIR)/get_next_line.c \
		$(F_DIR)/order.c \
		$(F_DIR)/info.c \
		$(F_DIR)/clean.c
CHECKER = $(FILES) $(F_DIR)/checker.c
PUSH_SWAP = $(FILES) $(F_DIR)/push_swap.c 
TMP = Makefile~ $(NAME2)~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME) $(NAME2)

$(NAME) :
	@cd $(L_DIR) && $(MAKE)
	@$(CC) -o $(NAME) $(FLAGS) $(PUSH_SWAP) -I $(H_DIR) -L $(L_DIR) -lft

$(NAME2) :
	@$(CC) -o $(NAME2) $(FLAGS) $(CHECKER) -I $(H_DIR) -L $(L_DIR) -lft

clean :
	@rm -f $(TMP) $(OBJ)
	@cd $(L_DIR) && $(MAKE) $@

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@cd $(L_DIR) && $(MAKE) $@
	@rm -f libft.a

re : fclean all

.PHONY : all clean fclean re
