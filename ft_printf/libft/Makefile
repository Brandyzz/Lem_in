# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 15:11:21 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/21 15:11:25 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC	=	ft_memalloc.c ft_memset.c ft_bzero.c ft_isdigit.c\
		ft_putchar.c ft_putnbr.c ft_putstr.c ft_putstr_until.c\
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strlen.c ft_strncpy.c\
		ft_strnew.c ft_itoa_base.c ft_strjoin.c ft_strcat.c ft_strjoin_leak.c\
		ft_itoa_ubase.c ft_ltoa_base.c ft_abs.c ft_strsub.c ft_strcmp.c\
		ft_copyuntil.c ft_strchr.c ft_strjoinch.c ft_strncat.c ft_strshift.c\
		ft_chjoinstr.c ft_nchjoinstr.c

OBJ = $(SRC:.c=.o)

F = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32mlibft.a was built\033[0m"


$(OBJ): $(SRC)
	@gcc $F -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette
