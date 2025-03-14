/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:01 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/14 23:50:23 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

static void	start_init(char **data_file)
{
	init_th_box(data_file);
	player()->move_count = 0;
	set_colictables();
	set_exit();
	init_wall();
	init_frames();
	fill_th_ocean();
	render_platform();
}

static void	no_reach_msg(void)
{
	ft_putstr_fd("Error: The player cannot ", 2);
	ft_putstr_fd("reach all collectibles", 2);
	ft_putstr_fd("or the exit. ", 2);
	ft_putstr_fd("Check the map's accessibility.\n", 2);
	exit (1);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**data_file;
	char	**dup;

	if (ac != 2)
		return (ft_putendl_fd
			("syntax error: ./so_long <path/to/file/map>", 2), 1);
	fd = safer_open(av[1]);
	data_file = the_parent_parser(fd);
	dup = mapdup(data_file);
	if (!dup)
		return (perror(""), 1);
	flood_fill(player()->updated_x, player()->updated_y, dup);
	if (!check_all_colictable(dup, data_file))
		no_reach_msg ();
	start_init(data_file);
	mlx_loop_hook (box()->mlx, update_frame, NULL);
	mlx_hook (box()->win, 17, 1L << 2, quite_nd_destroy, NULL);
	mlx_key_hook(box()->win, update_player_pos, NULL);
	mlx_loop(box()->mlx);
	return (0);
}
