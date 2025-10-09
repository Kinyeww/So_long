NAME = so_long
CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iget_next_line

MLX = ./minilibx-linux
SRCS = main.c minilbx.c parsing_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
MLXFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm

$(NAME): $(OBJS)
	make -C minilibx-linux
	@$(CC) $(CCFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo files compiled successfully!

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo object files deleted successfully!

fclean: clean
	@rm -f $(NAME)
	@echo [$(NAME).a] deleted successfully!

re: fclean all

.PHONY: all clean fclean re