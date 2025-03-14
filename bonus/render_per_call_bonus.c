/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_per_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:22:02 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 03:01:34 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_ocean(int x, int y)
{
	mlx_put_image_to_window(box()->mlx,
		box()->win, wall()->img_sea, x, y);
}

void	spawn_player(int x, int y)
{
	mlx_put_image_to_window(box()->mlx,
		box()->win, box()->p_status, x * 32 + 2, y * 32 + 4);
}

void	render_count_move(void)
{
	mlx_put_image_to_window(box()->mlx, box()->win,
		player_moves()->nbrs[player_moves()->move_count % 10], 3 * 32, 0);
	mlx_put_image_to_window(box()->mlx, box()->win,
		player_moves()->nbrs[(player_moves()->move_count / 10) % 10],
		2 * 32, 0);
	mlx_put_image_to_window(box()->mlx, box()->win,
		player_moves()->nbrs[(player_moves()->move_count / 100) % 10],
		1 * 32, 0);
	mlx_put_image_to_window(box()->mlx, box()->win,
		player_moves()->nbrs[(player_moves()->move_count / 1000) % 10],
		0, 0);
}

void	spawn_colictables(int x, int y)
{
	if (player_dir()->c_frame_index == 10)
		player_dir()->c_frame_index = 0;
	mlx_put_image_to_window(box()->mlx, box()->win,
		player_dir()->colictable[player_dir()->c_frame_index],
		x * 32 + 2, y * 32 + 4);
}

void	spawn_drown_zone(int x, int y)
{
	if (box()->map[y][x - player()->enemy_direction] == '0'
		&& !(player()->y == y
		&& player()->x == (x - player()->enemy_direction)))
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->floor, (x - player()->enemy_direction) * 32 + 2,
			y * 32 + 4);
	if (box()->map[y][x + player()->enemy_direction] == '0'
		&& !((player()->y == y
		&& player()->x == (x + player()->enemy_direction))))
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->floor, (x + player()->enemy_direction) * 32 + 2,
			y * 32 + 4);
	if (player()->enemy_direction == -1)
		mlx_put_image_to_window(box()->mlx,
			box()->win, player()->left_game,
			x * 32 + 2, y * 32 + 4);
	else if (player()->enemy_direction == 1)
		mlx_put_image_to_window(box()->mlx,
			box()->win, player()->right_game,
			x * 32 + 2, y * 32 + 4);
}
