/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:01 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/13 19:26:20 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	start_initialize(char **data_file)
{
	init_th_box(data_file);
	move_counter_seter();
	set_colictables();
	init_enemy();
	set_exit();
	init_wall();
	init_frames();
	fill_th_ocean();
	render_platform();
}

int	main(int ac, char **av)
{
	int		fd;
	char	**data_file;
	char	**dup;

	if (ac < 2)
		return (ft_putendl_fd
			("syntax error: ./so_long <path/to/file/map>", 2), 1);
	fd = safer_open(av[1]);
	data_file = the_parent_parser(fd);
	dup = mapdup(data_file);
	flood_fill(player()->updated_x, player()->updated_y, dup);
	if (!check_all_colictable(dup))
	{
		ft_putendl_fd("Error: The player cannot reach all ", 2);
		ft_putendl_fd("collectibles or the exit. ", 2);
		ft_putendl_fd("Check the map's accessibility.\n", 2);
		ft_free(data_file);
		return (1);
	}
	start_initialize(data_file);
	mlx_loop_hook(box()->mlx, update_frame, NULL);
	mlx_key_hook(box()->win, update_player_pos, NULL);
	mlx_loop(box()->mlx);
	return (0);
}
