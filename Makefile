SRC= so_long.c
CC= cc
CFLAGS= -Wall -Werror -Wextra
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