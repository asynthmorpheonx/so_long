/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:01 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/07 03:17:24 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

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

void		spawn_player(int x, int y)
{
	mlx_put_image_to_window(box()->mlx, box()->win, box()->p_status, x * 32 + 2, y * 32 + 4);
}

void	render_platform(void)
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
	else if (box()->map[player()->updated_y][player()->updated_x] == 'X')
	{
		mlx_destroy_window(box()->mlx, box()->win);
		start_clear();
		exit(0);
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

void	iterate_for_render_colictables(void)
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
			else if (box()->map[i][j] == 'X')
				spawn_drown_zone(j, i);
			j++;
		}
		i++;
	}
	player_dir()->c_frame_index++;
	player_dir()->e_frame_index++;
}

void	spawn_colictables(int x, int y)
{
	if (player_dir()->c_frame_index == 10)
		player_dir()->c_frame_index = 0;
	mlx_put_image_to_window(box()->mlx, box()->win, player_dir()->colictable[player_dir()->c_frame_index], x * 32 + 2, y * 32 + 4);
}

void	spawn_drown_zone(int x, int y)
{
	if (player_dir()->e_frame_index == 9)
		player_dir()->e_frame_index = 0;
	mlx_put_image_to_window(box()->mlx, box()->win, player_dir()->water_hole[player_dir()->e_frame_index], x * 32 + 2, y * 32 + 4);
}

void	init_danger_positions(void)
{
	int	garbage;

	player_dir()->water_hole[0] = mlx_xpm_file_to_image(box()->mlx, "./textures/en00.xpm", &garbage, &garbage);
	player_dir()->water_hole[1] = mlx_xpm_file_to_image(box()->mlx, "./textures/en01.xpm", &garbage, &garbage);
	player_dir()->water_hole[2] = mlx_xpm_file_to_image(box()->mlx, "./textures/en02.xpm", &garbage, &garbage);
	player_dir()->water_hole[3] = mlx_xpm_file_to_image(box()->mlx, "./textures/en03.xpm", &garbage, &garbage);
	player_dir()->water_hole[4] = mlx_xpm_file_to_image(box()->mlx, "./textures/en04.xpm", &garbage, &garbage);
	player_dir()->water_hole[5] = mlx_xpm_file_to_image(box()->mlx, "./textures/en05.xpm", &garbage, &garbage);
	player_dir()->water_hole[6] = mlx_xpm_file_to_image(box()->mlx, "./textures/en06.xpm", &garbage, &garbage);
	player_dir()->water_hole[7] = mlx_xpm_file_to_image(box()->mlx, "./textures/en07.xpm", &garbage, &garbage);
	player_dir()->water_hole[8] = mlx_xpm_file_to_image(box()->mlx, "./textures/en08.xpm", &garbage, &garbage);
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
	i = 0;
	while (i < 9)
	{
		mlx_destroy_image(box()->mlx, player_dir()->water_hole[i]);
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
	char	**dup;
	
	if (ac < 2)
		return (ft_putendl_fd("syntax error: ./so_long <path/to/file/map>", 2), 1);
	fd = safer_open(av[1]);
	data_file = the_parent_parser(fd);
	dup = mapdup(data_file);
	flood_fill(player()->updated_x, player()->updated_y, dup);
	if (!check_all_colictable(dup))
	{
		printf("Error: The player cannot reach all collectibles or the exit. Check the map's accessibility.\n");
		ft_free(data_file);
		close(fd);
		return (1);
	}
	init_th_box(data_file);
	set_colictables();
	init_danger_positions();
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
