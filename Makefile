# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 10:41:23 by kmaeda            #+#    #+#              #
#    Updated: 2025/07/08 10:41:29 by kmaeda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -ILibft

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

EXE = so_long
EXE_SRCS = so_long.c so_long_utils.c map_check.c map_utils.c cleaner_utils.c \
	   texture_utils.c animation_utils.c so_long_bonus.c
EXE_OBJS = $(EXE_SRCS:.c=.o)

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME) $(EXE)

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning MiniLibX..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(EXE_OBJS)
	ar rcs $(NAME) $(EXE_OBJS)

$(EXE): $(NAME) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(NAME) $(MLX_FLAGS) $(LIBFT_LIB) -o $(EXE)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(EXE_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	@if [ -d $(MLX_DIR) ]; then $(MAKE) clean -C $(MLX_DIR); fi

fclean: clean
	rm -f $(NAME) $(EXE) test_game
	$(MAKE) fclean -C $(LIBFT_DIR)
	@if [ -d mlx ]; then rm -rf mlx; fi

re: fclean all

test: $(NAME) $(LIBFT_LIB) $(MLX_LIB)
	gcc $(CFLAGS) -g -no-pie $(NAME) $(MLX_FLAGS) $(LIBFT_LIB) -o test_game
	@echo "Running test_game"
	@valgrind --leak-check=full ./test_game maps/map4.ber
	@rm -f test_game

.PHONY: all clean fclean re

