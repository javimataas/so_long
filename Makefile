# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 17:08:11 by jmatas-p          #+#    #+#              #
#    Updated: 2023/06/05 20:04:35 by jmatas-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror

LIBFT = 	libft/libft.a

MLX42 = 	MLX42/libmlx42.a

GREEN =		\033[0;32m

SRC =   	main.c map_load.c map_check.c utils.c errors.c \
			count_utils.c path_check.c renderers.c game_init.c \
			load_utils.c moves.c

OBJ = 		$(SRC:.c=.o)

NAME = 		so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/jmatas-p/.brew/opt/glfw/lib/" -o $(NAME)
	@echo "$(GREEN)Project compiled successfully!"

$(LIBFT):
	@make -C libft

$(MLX42):
	@make -C MLX42/

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make clean -C MLX42/
	@echo "$(GREEN)All clear"

re: fclean all

.PHONY: all clean fclean re bonus
