# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 19:44:28 by gade-oli          #+#    #+#              #
#    Updated: 2024/05/02 14:40:09 by gade-oli         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRC = src/fdf.c \
	  src/utils/errors.c \
	  src/utils/free_matrix.c \
	  src/utils/abs.c \
	  src/parser.c \
	  src/parser_utils.c \
	  src/window.c \
	  src/draw.c \
	  src/map.c \
	  src/mousehooks.c \
	  src/keyhooks.c

OBJ = $(SRC:src/%.c=bin/%.o)

INC = inc/defines.h \
	  inc/fdf.h

UNAME = $(shell uname -s)

#libft-----------------------------------------------------------

LIBFT_DIR = libs/libft/
LIBFT = $(LIBFT_DIR)libft.a

#libft-----------------------------------------------------------

PRINTF_DIR = libs/printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

#minilibx--------------------------------------------------------

MLX_DIR = libs/minilibx-linux/
MLX = $(MLX_DIR)libmlx_$(UNAME).a
#MLX = /usr/local/lib/libmlx.a #if you already have it locally

#MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm
# !!! CAUTION: apply this on linux system
MLX_FLAGS = -lm -lXext -lX11

#recipes---------------------------------------------------------

all:	$(NAME)

bin/%.o:	src/%.c $(INC)
		@echo $(BLUE)"compiling binaries..."$(RESET)
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make --directory=$(LIBFT_DIR)
		@echo $(GREEN)"libft compiled!"$(RESET)

$(PRINTF):
		@make --directory=$(PRINTF_DIR)
		@echo $(GREEN)"ft_printf compiled!"$(RESET)

$(MLX):
		@make --directory=$(MLX_DIR)
		@echo $(GREEN)"minilibx_$(UNAME) compiled!"$(RESET)

$(NAME):	$(LIBFT) $(PRINTF) $(OBJ) $(MLX)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS)
		@echo $(GREEN)"fdf compiled!"$(RESET)

clean:
		rm -rf bin/
		@make clean --directory=$(LIBFT_DIR)
		@make clean --directory=$(PRINTF_DIR)
		@echo $(RED)"binaries deleted!"$(RESET)

fclean: clean
		@make fclean --directory=$(LIBFT_DIR)
		@make fclean --directory=$(PRINTF_DIR)
		rm -f $(NAME)
		@echo $(RED)"fdf deleted!"$(RESET)

re: fclean all

.PHONY: all clean fclean re bonus
