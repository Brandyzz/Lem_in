# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 18:22:40 by cpollich          #+#    #+#              #
#    Updated: 2019/09/23 15:02:51 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
F = -Wall -Wextra -Werror

LIBFT = ./libft
SRC = ./src
INC = ./inc
OBJ = ./obj

SRCC	=	ft_printf.c\
			parser.c\
			print_char.c\
			print_dec.c\
			print_octal.c\
			print_hex.c\
			print_pointer.c\
			print_string.c\
			helper.c\
			print_num.c\
			print_unsigned.c\
			float_dec.c\
			float_div.c\
			float_help.c\
			float_round.c\
			float_sign.c\
			float_str.c\
			float_sum.c\
			float_width.c\
			ft_print_float.c\
			print_double.c\
			dbl_to_str.c\
			bin_transform.c\
			str_adding.c\
			ft_str_op.c

OBJS = $(addprefix $(OBJ)/,$(SRCC:%.c=%.o))
LIBFT_LIB = $(LIBFT)/libft.a
LIBFT_H = $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIBFT)/*.o
	@ranlib $(NAME)
	@echo "\033[1;32mlibftprintf.a was built\033[0m"

$(OBJ):
	@mkdir -p $(OBJ)

$(LIBFT_LIB):
	@make -C libft

$(OBJ)/%.o: $(SRC)/%.c
	@gcc $F -c $< -I$(INC) -I$(LIBFT_H) -o $@

clean:
	@rm -Rf $(OBJ)
	@make -C libft clean


fclean: clean
	@rm -Rf $(NAME)
	@make -C libft fclean
	@echo "\033[3;36mProject cleaned\033[0m"


re: fclean all

norm:
	norminette

test: $(LIBFT)
	@gcc -g -Wall -Wextra main.c $(NAME) $(LIBFT_LIB) -I./inc -I./libft -o test
