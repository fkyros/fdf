CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MLX = /usr/local/lib/libmlx.a
LIBFT = ../libs/libft/libft.a
PRINTF = ../libs/printf/libftprintf.a
SRC_PARSER = ../src/parser/*.c
SRC_UTILS = ../src/utils/*.c

SRC_TPARSER = parser_test/read_file_test.c

parser: $(SRC_TPARSER)
	$(CC) $(CFLAGS) $(SRC_PARSER) $(SRC_TPARSER) $(SRC_UTILS) $(LIBFT) $(PRINTF) -o $@

clean:
	rm parser
