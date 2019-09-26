# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 19:35:46 by jjory-ca          #+#    #+#              #
#    Updated: 2019/09/06 16:47:37 by jjory-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
C_DIR = src
O_DIR = obj
INCLUDES = -I ./inc -I ./libft
C_FILES = src/free_list.c \
	src/init_graph.c \
	src/parse.c \
	src/list.c \
	src/main.c \
	src/parse_helper.c \
	src/errors.c \
	src/parse_room.c \
	src/get_path.c \
	src/parse_edge.c

O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME): $(O_FILES)
	make -C libft
	@gcc $(FLAGS) -L./libft -libft $(O_FILES) -o $(NAME)

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIR)
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $< 
clean :
	@rm -rf $(O_DIR)
	@make clean -C ./libft
	@echo "Objects cleaned"

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "Deleted exec"

re : fclean all