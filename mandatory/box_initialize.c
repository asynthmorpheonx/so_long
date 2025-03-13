/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:11:01 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 00:14:02 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

void	init_th_box(char **map)
{
	box()->map = map;
	box()->mlx = mlx_init();
	box()->width = ft_strlen(map[0]) * 32;
	box()->hight = export_y(map) * 32 + 32;
	box()->win = mlx_new_window(box()->mlx,
		box()->width, box()->hight, "so_long");
}

void	init_wall(void)
{
	int	garbage;

	wall()->top = mlx_xpm_file_to_image(box()->mlx,
		"./textures/top.xpm", &garbage, &garbage);
	wall()->left = mlx_xpm_file_to_image(box()->mlx,
		"./textures/left.xpm", &garbage, &garbage);
	wall()->right = mlx_xpm_file_to_image(box()->mlx,
		"./textures/right.xpm", &garbage, &garbage);
	wall()->normal = mlx_xpm_file_to_image(box()->mlx,
		"./textures/block00.xpm", &garbage, &garbage);
	wall()->tright = mlx_xpm_file_to_image(box()->mlx,
		"./textures/topright.xpm", &garbage, &garbage);
	wall()->tleft = mlx_xpm_file_to_image(box()->mlx,
		"./textures/topleft.xpm", &garbage, &garbage);
	wall()->sea = mlx_xpm_file_to_image(box()->mlx,
		"./textures/sea.xpm", &garbage, &garbage);
	wall()->floor = mlx_xpm_file_to_image(box()->mlx,
		"./textures/b00.xpm", &garbage, &garbage);
	if (!wall()->floor || !wall()->sea || !wall()->tleft || !wall()->tright
		|| !wall()->normal || !wall()->right || !wall()->left || !wall()->top)
	{
		ft_putendl_fd("Error\n", 2);
		start_clear(1);
	}
}

void	init_frames(void)
{
	int	garbage;

	player_dir()->rframe = mlx_xpm_file_to_image(box()->mlx,
		"./textures/r00.xpm", &garbage, &garbage);
	if (!player_dir()->rframe)
	{
		ft_putendl_fd("Error\n", 2);
		start_clear(1);
	}
}

void	set_colictables(void)
{
	int	garbage;

	player_dir()->colictable = mlx_xpm_file_to_image(box()->mlx,
		"./textures/col00.xpm", &garbage, &garbage);
	if (!player_dir()->colictable)
	{
		ft_putendl_fd("Error\n", 2);
		start_clear(1);
	}
}

void	set_exit(void)
{
	int	garbage;

	(player_dir()->exit_hole)[0] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/e04.xpm", &garbage, &garbage);
	(player_dir()->exit_hole)[1] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/e03.xpm", &garbage, &garbage);
	if (!(player_dir()->exit_hole)[1] || !(player_dir()->exit_hole)[0])
	{
		ft_putendl_fd("Error\n", 2);
		start_clear(1);
	}
	(player_dir()->exit_hole)[2] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/e02.xpm", &garbage, &garbage);
	(player_dir()->exit_hole)[3] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/e01.xpm", &garbage, &garbage);
	(player_dir()->exit_hole)[4] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/e00.xpm", &garbage, &garbage);
	if (!(player_dir()->exit_hole)[4] ||
		!(player_dir()->exit_hole)[3] || !(player_dir()->exit_hole)[2])
	{
		ft_putendl_fd("Error\n", 2);
		start_clear(1);
	}
}
