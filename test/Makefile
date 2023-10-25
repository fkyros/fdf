CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = /usr/local/lib/libmlx.a
LIBFT = ../libs/libft/libft.a
SRC_PARSER = ../src/parser/*.c
SRC_UTILS = ../src/utils/*.c

SRC_TPARSER = parser_test/*.c

parser:
	$(CC) $(CFLAGS) $(SRC_PARSER) $(SRC_TPARSER) $(SRC_UTILS) $(LIBFT) -o $@
