# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 09:32:29 by nhuber            #+#    #+#              #
#    Updated: 2019/10/11 17:50:15 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

FLAGS = -Wall -Wextra -Werror
LIBA = -I libft/libft.h -L./libft -lft

SRC =   operations.c \
		check_med.c \
		error.c \
		more_er.c \
		get.c \
		init_point.c \
		do_left.c \
		do_right.c \
		solve.c \
		init.c \
		get_next_line.c \
		more_solve.c \
		free.c

OBJ = $(SRC:.c=.o)


all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJ)
	@echo ""
	@echo "===========[ \x1b[31mP \x1b[32mS \x1b[37m]==========="
	@echo ""
	@echo "\x1b[31m > \x1b[32mCompilation PUSH_SWAP...\x1b[37m"
	@make -C libft/
	@echo ""
	@echo "\x1b[31m > \033[1;35mLibft was built\033[0m"
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@gcc $(FLAGS) $(OBJ) push_swap.c -o $(PUSH_SWAP) $(LIBA)

$(CHECKER):  $(OBJ)
	@gcc $(FLAGS) $(OBJ) checker.c -o $(CHECKER) $(LIBA)
	@echo ""
	@echo "\x1b[31m > \033[1;32mProject was built\033[0m"
	@rm *.o
	@echo ""
clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo ""
	@echo "\x1b[31m > \033[3;36mObjects cleaned\033[0m"
	@echo ""

fclean: clean
	@rm -rf $(PUSH_SWAP) $(CHECKER)
	@make -C libft/ fclean
	@echo "\x1b[31m > \033[3;31mProject fully cleaned\033[0m"

re: fclean all
