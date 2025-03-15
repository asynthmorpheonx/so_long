/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:01:50 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/15 01:04:51 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_LONG_H
# define TO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "../so_libft/libft.h"
# include "../so_printf/ft_printf.h"

# define ESC_CODE 65307
# define D_CLICK 100
# define A_CLICK 97
# define W_CLICK 119
# define S_CLICK 115

typedef struct s_element
{
	int	colictable;
	int	player;
	int	map_exit;
	int	others;
}	t_elements;

typedef struct s_plate
{
	void	*top;
	void	*tright;
	void	*tleft;
	void	*right;
	void	*left;
	void	*normal;
	void	*sea;
	void	*floor;
}	t_plate;

typedef struct s_player
{
	int		flage_walk;
	int		y;
	int		x;
	int		updated_x;
	int		updated_y;
	int		move_count;
}	t_game;

typedef struct s_anime
{
	void	*rframe;
	void	*colictable;
	void	*exit_hole[5];
	int		h_pos[2];
	int		e_frame_index;
}	t_anime;

typedef struct s_box
{
	void	*mlx;
	void	*win;
	char	**map;
	int		hight;
	int		width;
	int		*garbage;
}	t_box;

int			safer_open(char *file_path);
char		**data_splited(char *data_file);
char		*data_file_parser(int fd);
void		ft_free(char **str);
void		iterate_on_map(char **map);
char		**the_parent_parser(int map_fd);
void		map_validation_error(void);
void		check_newlines(char *map);
void		check_for_elements(char **map);
int			check_element(char **map);
t_game		*player(void);
int			export_y(char **map);
t_box		*box(void);
void		init_th_box(char **map);
t_plate		*wall(void);
void		init_wall(void);
void		render_ocean(int x, int y);
void		fill_th_ocean(void);
void		render_for_each_direction(int i, int j);
void		spawn_player(int x, int y);
void		p_pos(int y, int x, int f_walk);
void		spawn_colictables(int x, int y);
void		set_colictables(void);
t_elements	*elements(void);
void		iterate_for_render(void);
void		start_clear(int i);
void		spawn_exit(int y, int x);
void		set_exit(void);
t_anime		*player_dir(void);
char		**mapdup(char **map);
void		flood_fill(int x, int y, char **map);
int			check_all_colictable(char **map, char **data_file);
void		init_frames(void);
void		print_if_error(int i, char **map);
int			update_frame(void);
int			update_player_pos(int kcode);
void		render_platform(void);
int			quite_nd_destroy(void);
void		show_exit(void);

#endif