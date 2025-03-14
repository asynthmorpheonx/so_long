/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_count_nd_enemy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:21:28 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 00:32:33 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_enemy(void)
{
	int	garbage;

	player()->right_game = mlx_xpm_file_to_image(box()->mlx,
		"./textures/enr.xpm", &garbage, &garbage);
	player()->left_game = mlx_xpm_file_to_image(box()->mlx,
		"./textures/enl.xpm", &garbage, &garbage);
	if (!player()->left_game || !player()->right_game)
	{
		ft_putstr_fd("Error\n", 2);
		start_clear(1);
	}
	player()->enemy_direction = 1;
	player()->enemy_xp = malloc(sizeof(int) * elements()->enemy);
	player()->enemy_yp = malloc(sizeof(int) * elements()->enemy);
	set_game_pos();
}

void	check_enemy(void)
{
	if (!player()->left_game || !player()->right_game
		|| !player()->enemy_xp || !player()->enemy_yp)
	{
		ft_putstr_fd("Error\n", 2);
		start_clear(1);
	}
}

void	move_counter_seter(void)
{
	int	garbage;

	(player_moves()->nbrs)[0] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n0.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[1] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n1.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[2] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n2.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[3] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n3.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[4] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n4.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[5] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n5.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[6] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n6.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[7] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n7.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[8] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n8.xpm", &garbage, &garbage);
	(player_moves()->nbrs)[9] = mlx_xpm_file_to_image(box()->mlx,
			"./textures/n9.xpm", &garbage, &garbage);
	check_counter();
}
