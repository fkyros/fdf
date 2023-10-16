# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 19:44:28 by gade-oli          #+#    #+#              #
#    Updated: 2023/10/16 22:37:21 by gade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors----------------------------------------------------------

RED 	= '\033[1;31m'
GREEN   = '\033[1;32m'
BLUE    = '\033[1;34m'
RESET   = '\033[0;0m'

#variables-------------------------------------------------------

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = src/fdf.c \
	  src/utils/ft_error.c \
	  src/utils/free_matrix.c \
	  src/parser/read_file.c
OBJ = $(SRC:src/%.c=bin/%.o)

#libft-----------------------------------------------------------

LIBFT_DIR = libs/libft/
LIBFT = $(LIBFT_DIR)libft.a

#minilibx--------------------------------------------------------

MLX_DIR = libs/mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm

#recipes---------------------------------------------------------

all:	$(NAME)

bin/%.o:	src/%.c inc/fdf.h
		@echo $(BLUE)"compiling binaries..."$(RESET)
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make --directory=$(LIBFT_DIR)
		@echo $(GREEN)"libft compiled!"$(RESET)

$(NAME):	$(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		@echo $(GREEN)"fdf compiled!"$(RESET)

clean:
		rm -rf bin/
		@make clean --directory=$(LIBFT_DIR)
		@echo $(RED)"binaries deleted!"$(RESET)

fclean: clean
		@make fclean --directory=$(LIBFT_DIR)
		rm -f $(NAME)
		@echo $(RED)"fdf deleted!"$(RESET)

re: fclean all

.PHONY: all clean fclean re
