# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 04:39:28 by lkoletzk          #+#    #+#              #
#    Updated: 2023/02/14 16:02:22 by lkoletzk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = srcs/ft_utils.c \
		srcs/ft_map_checker.c \
		srcs/ft_map_solvability.c \
		srcs/ft_moves.c \
		srcs/ft_sprites.c \
		srcs/main.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = libft/libft.a

MINILIBX_DIR = ../minilibx-linux
MINILIBX = ../minilibx-linux/libmlx_Linux.a ../minilibx-linux/libmlx.a

CC = cc

CFLAGS = -Wall -Wextra -Werror
FLAGS = -lX11 -lXext

all : LIBFT $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) $(FLAGS)

LIBFT :
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX) :
	$(MAKE) -C $(MINILIBX_DIR)

%.o: (SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re
