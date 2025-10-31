NAME = so_long
CC = cc
CCFLAGS = -Wall -Wextra -Werror -Ift_printf -Iget_next_line

MLX = ./minilibx-linux
SRCS = So_long.c parsing.c parsing_utils_1.c parsing_utils_2.c exemlx.c mlx_utils_1.c mlx_utils_2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/ft_printf_utils.c ft_printf/ft_printf.c

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