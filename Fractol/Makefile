# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 15:25:33 by jjory-ca          #+#    #+#              #
#    Updated: 2019/10/07 18:38:19 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
ATTACH = -lmlx -framework OpenGL -framework AppKit -L./libft -lft
SRC = 	main.c\
		keys.c\
		init.c\
		mandelbrot.c\
		helper.c\
		color.c\
		mouse_hook.c\
		julia.c\
		multibrot.c\
		burningship.c

OBJ = $(subst .c,.o,$(SRC))
all: $(NAME)

$(NAME): $(SRC)

	@echo ""
	@echo "===========[ \x1b[31mF \x1b[32mR \x1b[34mA \x1b[36mC \x1b[37mT \x1b[35mA \x1b[34mL \x1b[37m]==========="
	@echo ""
	@echo "\x1b[31m > \x1b[32mCompilation fractal...\x1b[37m"
	@echo ""
	@make -C libft/
	@echo ""
	@echo "\x1b[31m > \033[1;35mLibft was built\033[0m"
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@gcc $(FLAGS) $(ATTACH) $(OBJ) -o $(NAME)
	@echo ""
	@echo "\x1b[31m > \033[1;32mProject was built\033[0m"
	@echo ""
	@echo "\x1b[31m > \033[1;32mHOW TO USE\033[0m"
	@echo "\x1b[31m -> \033[1;32mChoose from 3 fractals : mandelbrot, julia, burningship, or multibrot\033[0m"
	@echo "\x1b[31m -> \033[1;32mDo ./fractol <your choise>\033[0m"
	@echo "\x1b[31m < \033[1;32mENJOY =)\033[0m"
	
clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo ""
	@echo "\x1b[31m > \033[3;36mObjects cleaned\033[0m"
	@echo ""
fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "\x1b[31m > \033[3;31mProject fully cleaned\033[0m"

re: fclean all

norm:
	norminette
	