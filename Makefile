NAME = so_long
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -Iget_next_line

MLX = ./minilibx-linux
SRCS = main.c minilbx.c parsing_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
MLXFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
