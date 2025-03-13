SRC= mandatory/flood_fill_check.c mandatory/so_long.c mandatory/file_name_parser.c\
	mandatory/file_data_parser.c mandatory/iteration_nd_check.c mandatory/iteration_help_utils.c\
	mandatory/box_realease.c mandatory/box_initialize.c mandatory/destroy_nd_clear.c mandatory/render_utils.c\
	mandatory/user_handle.c
BSRC= bonus/flood_fill_check.c bonus/so_long.c bonus/file_name_parser.c bonus/file_data_parser.c bonus/iteration_nd_check.c \
	bonus/iteration_help_utils.c bonus/box_realease.c bonus/box_initialize.c bonus/render_per_call.c\
	bonus/rendering_loop_utils.c bonus/rendering_utils.c bonus/check_boxes.c bonus/clear_utils.c bonus/updating_nd_redraw.c\
	bonus/rendering_utils.c bonus/init_count_nd_enemy.c bonus/so_long_utils.c
OBJ= $(SRC:.c=.o)
BOBJ= $(BSRC:.c=.o)
CC= cc
CFLAGS= -Wall -Werror -Wextra  -Imlx_linux -g3
NAME= libs/libmlong.a
BNAME= libs/libblong.a
PRNAME= so_long
LIBFT= libs/libft.a libs/libftprintf.a

all: $(PRNAME)

$(PRNAME): $(NAME) $(LIBFT) 
	$(CC) $(CFLAGS) $(NAME) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibs -lft -lftprintf -o $(PRNAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C ft_printf
	make -C libft bonus

bonus: $(BNAME) 
	$(CC) $(CFLAGS) $(BNAME) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibs -lft -lftprintf -o $(PRNAME)

$(BNAME): $(BOBJ) $(LIBFT) 
	ar rcs $(BNAME) $(BOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BOBJ)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	rm -rf $(NAME) $(BNAME)
	rm -rf $(PRNAME)

re: fclean all
	make -C libft re 
	make -C ft_printf re 

.PHONY: clean fclean re

.SECONDARY: $(LIBFT)