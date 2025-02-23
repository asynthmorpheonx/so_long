SRC= so_long.c file_name_parser.c file_data_parser.c iteration_nd_check.c
CC= cc
CFLAGS= -Wall -Werror -Wextra -g3
NAME= so_long
LIBFT= libft.a

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -L./libft -lft -o $(NAME)

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