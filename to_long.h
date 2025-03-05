/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:01:50 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/05 17:13:34 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_LONG_H
# define TO_LONG_H

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <errno.h>

#define ESC_CODE 65307
#define D_CLICK 100
#define A_CLICK 97
#define W_CLICK 119
#define S_CLICK 115

typedef struct s_element
{
	int colictable;
	int player;
	int map_exit;
	int others;
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

typedef struct s_player
{
	int		flage_walk;
	int		y;
	int		x;
	int		updated_x;
	int		updated_y;
}	t_player;

typedef struct s_anime
{
	void	*tframe;
	void	*rframe;
	void	*lframe;
	void	*colictable[10];
	void	*exit_hole[5];
	int		h_pos[2];
	int		frame_index;
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


int			safer_open(char *file_path);
char		**data_splited(char *data_file);
char		*data_file_parser(int fd);
void		ft_free(char **str);
void		iterate_on_map(char **map, int fd);
char		**the_parent_parser(int map_fd);
void		map_validation_error(void);
void		check_newlines(char *map);
void		check_for_elements(char **map);
void		print_if_error(int i);
int			check_element(char **map);
t_player	*player();
int			export_y(char **map);
t_box		*box();
void		init_th_box(char **map);
t_plate		*wall();
void		init_wall();
void		render_ocean(int x, int y);
void		fill_th_ocean(void);
void		render_for_each_direction(int i, int j);
void		spawn_player(int x, int y);
void		p_pos(int y, int x, int f_walk);
void		spawn_colictables(int x, int y);
void		set_colictables();
t_elements	*elements();
void		iterate_for_render_colictables();
void		start_clear();
void	spawn_exit(int y, int x);
void		set_exit();

#endif