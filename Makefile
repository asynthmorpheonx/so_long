SRC= flood_fill_check.c so_long.c file_name_parser.c file_data_parser.c iteration_nd_check.c \
	iteration_help_utils.c box_realease.c box_initialize.c
CC= cc
CFLAGS= -Wall -Werror -Wextra  -Imlx_linux -g3
NAME= so_long
LIBFT= libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft -o $(NAME)

$(LIBFT):
	make -C libft bonus

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
	make -C libft re 

.PHONY: clean fclean re