/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:01:50 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/13 02:00:05 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <errno.h>

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
	int	enemy;
}	t_elements;

typedef struct s_plate
{
	void	*img_top;
	void	*img_tright;
	void	*img_tleft;
	void	*img_right;
	void	*img_left;
	void	*img_normal;
	void	*img_sea;
	void	*floor;
}	t_plate;

typedef struct s_game
{
	int		flage_walk;
	int		y;
	int		x;
	int		updated_x;
	int		updated_y;
	void	*right_game;
	void	*left_game;
	int		*enemy_xp;
	int		*enemy_yp;
	int		enemy_direction;
}	t_game;

typedef struct s_anime
{
	void	*tframe;
	void	*rframe;
	void	*lframe;
	void	*colictable[10];
	void	*exit_hole[5];
	int		h_pos[2];
	int		c_frame_index;
}	t_anime;

typedef struct s_box
{
	void	*p_status;
	void	*mlx;
	void	*win;
	char	**map;
	int		hight;
	int		width;
}	t_box;

typedef struct s_movement
{
	void	*nbrs[10];
	int		move_count;
}	t_movement;

int			safer_open(char *file_path);
char		**data_splited(char *data_file);
char		*data_file_parser(int fd);
void		ft_free(char **str);
void		iterate_on_map(char **map, int fd);
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
void		iterate_for_render_x(void);
void		iterate_for_render_c(void);
void		start_clear(int z);
void		spawn_exit(int y, int x);
void		set_exit(void);
t_anime		*player_dir(void);
char		**mapdup(char **map);
void		flood_fill(int x, int y, char **map);
int			check_all_colictable(char **map);
void		init_frames(void);
void		spawn_drown_zone(int x, int y);
void		print_if_error(int i, char **map);
t_movement	*player_moves(void);
void		update_enemy_pos(void);
void		render_count_move(void);
void		set_game_pos(void);
void		render_platform(void);
void		check_wall(void);
void		check_frames(void);
void		check_colictables(void);
void		check_exits(void);
void		check_counter(void);
int			update_player_pos(int kcode);
void		init_enemy(void);
void		move_counter_seter(void);
int			update_frame(void);
int			quite_nd_destroy(char *str);
void		re_check_enemy(void);
#endif