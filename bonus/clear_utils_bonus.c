/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:17:25 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:41:11 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	quite_nd_destroy(char *str)
{
	ft_printf("%s\n", str);
	start_clear(0);
	return (0);
}

void	destroy_wall(void)
{
	if (wall()->floor)
		mlx_destroy_image(box()->mlx, wall()->floor);
	if (wall()->img_left)
		mlx_destroy_image(box()->mlx, wall()->img_left);
	if (wall()->img_normal)
		mlx_destroy_image(box()->mlx, wall()->img_normal);
	if (wall()->img_right)
		mlx_destroy_image(box()->mlx, wall()->img_right);
	if (wall()->img_tleft)
		mlx_destroy_image(box()->mlx, wall()->img_tleft);
	if (wall()->img_tright)
		mlx_destroy_image(box()->mlx, wall()->img_tright);
	if (wall()->img_top)
		mlx_destroy_image(box()->mlx, wall()->img_top);
	if (wall()->img_sea)
		mlx_destroy_image(box()->mlx, wall()->img_sea);
}

void	destroy_game_content(void)
{
	if (player_dir()->tframe)
		mlx_destroy_image(box()->mlx, player_dir()->tframe);
	if (player_dir()->lframe)
		mlx_destroy_image(box()->mlx, player_dir()->lframe);
	if (player_dir()->rframe)
		mlx_destroy_image(box()->mlx, player_dir()->rframe);
	if (player()->right_game)
		mlx_destroy_image(box()->mlx, player()->right_game);
	if (player()->left_game)
		mlx_destroy_image(box()->mlx, player()->left_game);
}

void	destroy_animations(void)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (player_dir()->exit_hole[i])
			mlx_destroy_image(box()->mlx,
				player_dir()->exit_hole[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (player_dir()->colictable[i])
			mlx_destroy_image(box()->mlx,
				player_dir()->colictable[i]);
		if (player_moves()->nbrs[i])
			mlx_destroy_image(box()->mlx,
				player_moves()->nbrs[i]);
		i++;
	}
}

void	start_clear(int z)
{
	if (box()->map)
		ft_free(box()->map);
	if (box()->win)
		mlx_destroy_window(box()->mlx, box()->win);
	destroy_wall();
	destroy_game_content();
	destroy_animations();
	if (player()->enemy_xp)
		free(player()->enemy_xp);
	if (player()->enemy_yp)
		free(player()->enemy_yp);
	if (box()->mlx)
	{
		mlx_destroy_display(box()->mlx);
		free(box()->mlx);
	}
	exit (z);
}
