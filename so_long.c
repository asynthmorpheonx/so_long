/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:01 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/05 17:45:58 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

t_elements	*elements()
{
	static	t_elements pp;

	return (&pp);
}	

t_player	*player()
{
	static t_player	pp;

	return (&pp);
}

t_box	*box()
{
	static t_box	box;
	
	return(&box);
}

t_plate	*wall()
{
	static t_plate plate;
	
	return (&plate);
}

t_anime	*player_dir()
{
	static	t_anime pp;
	
	return (&pp);
}

void	init_th_box(char **map)
{
	box()->map = map;
	box()->mlx = mlx_init();
	box()->width = ft_strlen(map[0]) * 32;
	box()->hight = export_y(map) * 32 + 32;
	box()->win = mlx_new_window(box()->mlx, box()->width, box()->hight, "so_long");
}

int	export_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	init_wall()
{
	int garbage;
	
	wall()->img_top = mlx_xpm_file_to_image(box()->mlx, "./textures/top.xpm",  &garbage, &garbage);
	wall()->img_left = mlx_xpm_file_to_image(box()->mlx, "./textures/left.xpm", &garbage, &garbage);;
	wall()->img_right = mlx_xpm_file_to_image(box()->mlx, "./textures/right.xpm", &garbage, &garbage);
	wall()->img_normal = mlx_xpm_file_to_image(box()->mlx, "./textures/block00.xpm", &garbage, &garbage);
	wall()->img_tright = mlx_xpm_file_to_image(box()->mlx, "./textures/topright.xpm", &garbage, &garbage);
	wall()->img_tleft = mlx_xpm_file_to_image(box()->mlx, "./textures/topleft.xpm", &garbage, &garbage);
	wall()->img_sea = mlx_xpm_file_to_image(box()->mlx, "./textures/sea.xpm", &garbage, &garbage);
	wall()->floor = mlx_xpm_file_to_image(box()->mlx, "./textures/b00.xpm", &garbage, &garbage);
}

void	render_ocean(int x, int y)
{
	mlx_put_image_to_window(box()->mlx, box()->win, wall()->img_sea, x, y);
}

void	fill_th_ocean(void)
{
	int i;
	int j;
	
	i = 0;
	while (i < box()->hight)
	{
		j = 0;
		while (j < box()->width)
		{
			render_ocean(j, i);
			j += 32;
		}
		i += 32;
	}
}

//render the platform depenend on it's position
void	render_for_each_direction(int i, int j)
{
	if (box()->map[i][j - 1] == '1' && box()->map[i - 1][j] == '1')
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->img_tleft, j * 32, i * 32);
	else if (box()->map[i - 1][j] == '1'&& box()->map[i][j + 1] == '1')
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->img_tright, j * 32, i * 32);
	else if (box()->map[i - 1][j] == '1')
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->img_top, j * 32, i * 32);
	else if (box()->map[i][j + 1] && box()->map[i][j + 1] == '1')
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->img_right, j * 32, i * 32);
	else if (box()->map[i][j - 1] == '1')
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->img_left, j * 32, i * 32);
	else
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->img_normal, j * 32, i * 32);
}

//render the platform depend on it's position
void		spawn_player(int x, int y)
{
	mlx_put_image_to_window(box()->mlx, box()->win, box()->p_status, x * 32 + 2, y * 32 + 4);
}

void	spawn_exit(int y, int x)
{
	mlx_put_image_to_window(box()->mlx, box()->win, player_dir()->exit_hole[0], x * 32 + 2, y * 32 + 4);
}

void	render_platform()
{
	int	i;
	int	j;
	
	i = 0;
	while (box()->map[i])
	{
		j = 0;
		while (box()->map[i][j])
		{
			if (box()->map[i][j] != '1')
				render_for_each_direction(i, j);
			if (box()->map[i][j] == 'C')
				spawn_colictables(j, i);
			else if (box()->map[i][j] == 'E')
			{
				player_dir()->h_pos[0] = j;
				player_dir()->h_pos[1] = i;
			}
			j++;
		}
		i++;
	}
	spawn_player(player()->updated_x, player()->updated_y);
}

int	update_player_pos(int kcode)
{
	if (ESC_CODE == kcode)
	{
		mlx_destroy_window(box()->mlx, box()->win);
		start_clear();
		exit(0);
	}
	else if (D_CLICK == kcode)
	{
		if (box()->map[player()->updated_y][player()->updated_x + 1] != '1')
			p_pos(player()->updated_y, ++player()->updated_x, 1);
		box()->p_status = player_dir()->rframe;
	}
	else if (A_CLICK == kcode)
	{
		if (box()->map[player()->updated_y][player()->updated_x - 1] != '1')
			p_pos(player()->updated_y, --player()->updated_x, 1);
		box()->p_status = player_dir()->lframe;
	}
	else if (W_CLICK == kcode)
	{
		if (box()->map[player()->updated_y - 1][player()->updated_x] != '1')
			p_pos(--player()->updated_y, player()->updated_x, 1);
		box()->p_status = player_dir()->tframe;
	}
	else if (S_CLICK == kcode)
	{
		if (box()->map[player()->updated_y + 1][player()->updated_x] != '1')
			p_pos(++player()->updated_y, player()->updated_x, 1);
		box()->p_status = player_dir()->lframe;
	}
	if (box()->map[player()->updated_y][player()->updated_x] == 'C')
	{
		box()->map[player()->updated_y][player()->updated_x] = '0';
		elements()->colictable--;
	}
	player()->flage_walk = 1;
	return (0);
}

void	p_pos(int y, int x, int f_walk)
{
	player()->updated_y = y;
	player()->updated_x = x;
	player()->flage_walk = f_walk;
}

// rendering the frames
int	update_frame(void)
{
	static unsigned int curr_frame;
	static int i;

	if (curr_frame % 4100 == 0)
	{
		if (elements()->colictable == 0)
		{
			if (i < 5)
				mlx_put_image_to_window(box()->mlx, box()->win, player_dir()->exit_hole[i], player_dir()->h_pos[0] * 32 + 2, player_dir()->h_pos[1] * 32 + 4);
			// printf("y=%d\nx=%d\n",player_dir()->h_pos[1],player_dir()->h_pos[0]);
			i++;
		}
		else
			mlx_put_image_to_window(box()->mlx, box()->win, player_dir()->exit_hole[0], player_dir()->h_pos[0] * 32 + 2, player_dir()->h_pos[1] * 32 + 4);
		if (player()->flage_walk == 1)
			mlx_put_image_to_window(box()->mlx, box()->win, wall()->floor, player()->x * 32 + 2, player()->y * 32 + 4);
		spawn_player(player()->updated_x, player()->updated_y);
		player()->x = player()->updated_x;
		player()->y = player()->updated_y;
		player()->flage_walk = 0;
		iterate_for_render_colictables();
	}
	curr_frame++;
	if (box()->map[player()->updated_y][player()->updated_x] == 'E' && elements()->colictable == 0)
	{
		mlx_destroy_window(box()->mlx, box()->win);
		start_clear();
		exit(0);
	}
	return (0);
}

//initialaize the player directions
void	init_frames()
{
	int	garbage;

	player_dir()->rframe = mlx_xpm_file_to_image(box()->mlx, "./textures/r00.xpm", &garbage, &garbage);
	player_dir()->lframe = mlx_xpm_file_to_image(box()->mlx, "./textures/l00.xpm", &garbage, &garbage);
	player_dir()->tframe = mlx_xpm_file_to_image(box()->mlx, "./textures/t00.xpm", &garbage, &garbage);
	box()->p_status = player_dir()->rframe;
}

//initialaize colictables
void	set_colictables()
{
	int	garbage;
	
	player_dir()->colictable[0] = mlx_xpm_file_to_image(box()->mlx, "./textures/col00.xpm", &garbage, &garbage);
	player_dir()->colictable[1] = mlx_xpm_file_to_image(box()->mlx, "./textures/col01.xpm", &garbage, &garbage);
	player_dir()->colictable[2] = mlx_xpm_file_to_image(box()->mlx, "./textures/col02.xpm", &garbage, &garbage);
	player_dir()->colictable[3] = mlx_xpm_file_to_image(box()->mlx, "./textures/col03.xpm", &garbage, &garbage);
	player_dir()->colictable[4] = mlx_xpm_file_to_image(box()->mlx, "./textures/col04.xpm", &garbage, &garbage);
	player_dir()->colictable[5] = mlx_xpm_file_to_image(box()->mlx, "./textures/col05.xpm", &garbage, &garbage);
	player_dir()->colictable[6] = mlx_xpm_file_to_image(box()->mlx, "./textures/col06.xpm", &garbage, &garbage);
	player_dir()->colictable[7] = mlx_xpm_file_to_image(box()->mlx, "./textures/col07.xpm", &garbage, &garbage);
	player_dir()->colictable[8] = mlx_xpm_file_to_image(box()->mlx, "./textures/col08.xpm", &garbage, &garbage);
	player_dir()->colictable[9] = mlx_xpm_file_to_image(box()->mlx, "./textures/col09.xpm", &garbage, &garbage);
}

void	set_exit()
{
	int garbage;

	player_dir()->exit_hole[0] = mlx_xpm_file_to_image(box()->mlx, "./textures/e04.xpm", &garbage, &garbage);
	player_dir()->exit_hole[1] = mlx_xpm_file_to_image(box()->mlx, "./textures/e03.xpm", &garbage, &garbage);
	player_dir()->exit_hole[2] = mlx_xpm_file_to_image(box()->mlx, "./textures/e02.xpm", &garbage, &garbage);
	player_dir()->exit_hole[3] = mlx_xpm_file_to_image(box()->mlx, "./textures/e01.xpm", &garbage, &garbage);
	player_dir()->exit_hole[4] = mlx_xpm_file_to_image(box()->mlx, "./textures/e00.xpm", &garbage, &garbage);
}

void	iterate_for_render_colictables()
{
	int	i;
	int	j;

	i = 0;
	while (box()->map[i])
	{
		j = 0;
		while (box()->map[i][j])
		{
			if (box()->map[i][j] == 'C')
				spawn_colictables(j, i);
			j++;
		}
		i++;
	}
	player_dir()->frame_index++;
}

void	spawn_colictables(int x, int y)
{

	if (player_dir()->frame_index == 10)
		player_dir()->frame_index = 0;
	mlx_put_image_to_window(box()->mlx, box()->win, player_dir()->colictable[player_dir()->frame_index], x * 32 + 2, y * 32 + 4);
}

void	start_clear()
{
	int	i;

	i = 0;
	mlx_destroy_image(box()->mlx, wall()->floor);
	mlx_destroy_image(box()->mlx, wall()->img_left);
	mlx_destroy_image(box()->mlx, wall()->img_normal);
	mlx_destroy_image(box()->mlx, wall()->img_right);
	mlx_destroy_image(box()->mlx, wall()->img_tleft);
	mlx_destroy_image(box()->mlx, wall()->img_tright);
	mlx_destroy_image(box()->mlx, wall()->img_top);
	mlx_destroy_image(box()->mlx, wall()->img_sea);
	mlx_destroy_image(box()->mlx, player_dir()->tframe);
	mlx_destroy_image(box()->mlx, player_dir()->lframe);
	mlx_destroy_image(box()->mlx, player_dir()->rframe);
	while (i < 5)
	{
		mlx_destroy_image(box()->mlx, player_dir()->exit_hole[i]);
		i++;
	}
	i = 0;
	while (i <= 9)
	{
		mlx_destroy_image(box()->mlx, player_dir()->colictable[i]);
		i++;
	}
	ft_free(box()->map);
	mlx_destroy_display(box()->mlx);
	free(box()->mlx);
}

int main(int ac, char **av)
{
	int		fd;
	char	**data_file;
	
	if (ac < 2)
		return (ft_putendl_fd("syntax error: ./so_long <path/to/file/map>", 2), 1);
	fd = safer_open(av[1]);
	data_file = the_parent_parser(fd);
	init_th_box(data_file);
	set_colictables();
	set_exit();
	init_wall();
	init_frames();
	fill_th_ocean();
	render_platform();
	mlx_loop_hook(box()->mlx, update_frame, NULL);
	mlx_hook(box()->win, 2, 1L<<0, update_player_pos, NULL);
	mlx_loop(box()->mlx);
	return (0);
}
