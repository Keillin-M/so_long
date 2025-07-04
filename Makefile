# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 12:50:34 by kmaeda            #+#    #+#              #
#    Updated: 2025/06/27 12:53:05 by kmaeda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -ILibft

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

EXE = so_long
EXE_SRCS = so_long.c so_long_utils.c map_check.c map_utils.c cleaner_utils.c \
	   texture_utils.c
EXE_OBJS = $(EXE_SRCS:.c=.o)

MLX_LIBS = -lmlx -lX11 -lXext -lm

all: $(NAME) $(EXE)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(EXE_OBJS) $(LIBFT_LIB)
	ar rcs $(NAME) $(EXE_OBJS)

$(EXE): $(NAME) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(NAME) $(MLX_LIBS) $(LIBFT_LIB) -o $(EXE)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(EXE_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(EXE) test_game
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

test: $(NAME) $(LIBFT_LIB)
	gcc $(CFLAGS) -g -no-pie $(NAME) $(MLX_LIBS) $(LIBFT_LIB) -o test_game
	@echo "Running test_game"
	@valgrind --leak-check=full ./test_game maps/map.ber
	@rm -f test_game

.PHONY: all clean fclean re
