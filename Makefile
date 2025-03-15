SRC= mandatory/flood_fill_check.c mandatory/so_long.c mandatory/file_name_parser.c\
	mandatory/file_data_parser.c mandatory/iteration_nd_check.c mandatory/iteration_help_utils.c\
	mandatory/box_realease.c mandatory/box_initialize.c mandatory/destroy_nd_clear.c mandatory/render_utils.c\
	mandatory/user_handle.c
BSRC= bonus/box_initialize_bonus.c bonus/file_data_parser_bonus.c bonus/iteration_help_utils_bonus.c bonus/render_per_call_bonus.c\
	bonus/box_realese_bonus.c bonus/file_name_parser_bonus.c bonus/iteration_nd_check_bonus.c bonus/so_long_bonus.c\
	bonus/check_boxes_bonus.c bonus/flood_fill_check_bonus.c bonus/rendering_loop_utils_bonus.c bonus/so_long_utils_bonus.c\
	bonus/clear_utils_bonus.c bonus/init_count_nd_enemy_bonus.c bonus/rendering_utils_bonus.c bonus/updating_nd_redraw_bonus.c\
	bonus/clear_utils_bonus.c


OBJ= $(SRC:.c=.o)
BOBJ= $(BSRC:.c=.o)
CC= cc
CFLAGS= -Wall -Werror -Wextra -Imlx_linux -g3
NAME= libs/libmlong.a
BNAME= libs/libblong.a
PRNAME= so_long
BPNAME= so_long_bonus
LIBFT= libs/libft.a
LIBFTP= libs/libftprintf.a
L_DIR= libs/

all: $(PRNAME)

$(PRNAME): $(L_DIR) $(NAME) 
	$(CC) $(CFLAGS) $(NAME) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llibs -lft -lftprintf -o $(PRNAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBFTP)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C so_libft bonus

$(LIBFTP):
	make -C so_printf

bonus: $(BPNAME)

$(BPNAME): $(L_DIR) $(BNAME)
	$(CC) $(CFLAGS) $(BNAME) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llibs -lft -lftprintf -o $(BPNAME)

$(BNAME): $(BOBJ) $(LIBFT) $(LIBFTP)
	ar rcs $(BNAME) $(BOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(L_DIR):
	mkdir libs

clean:
	rm -rf $(OBJ) $(BOBJ)
	make -C so_libft clean
	make -C so_printf clean

fclean: clean
	make -C so_libft fclean
	make -C so_printf fclean
	rm -rf $(NAME) $(BNAME)
	rm -rf $(PRNAME) $(BPNAME)

re: fclean all
	make -C so_libft re 
	make -C so_printf re 

.PHONY: clean fclean re

.SECONDARY: $(LIBFT) $(LIBFTP) $(BNAME) $(NAME) $(OBJ) $(BOBJ)