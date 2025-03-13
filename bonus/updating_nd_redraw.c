/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_nd_redraw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:18:52 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 01:59:23 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_th_hole(int	*i)
{
	if (*i < 5)
	{
		mlx_put_image_to_window(box()->mlx,
			box()->win, player_dir()->exit_hole[*i],
			player_dir()->h_pos[0] * 32 + 2, player_dir()->h_pos[1] * 32 + 4);
		*i += 1;
	}
}

void	set_player_nd_colictables(int curr_frame)
{
	if (curr_frame % 4500 == 0)
	{
		render_count_move();
		if (player()->flage_walk == 1)
			mlx_put_image_to_window(box()->mlx, box()->win,
				wall()->floor, player()->x * 32 + 2, player()->y * 32 + 4);
		spawn_player(player()->updated_x, player()->updated_y);
		player()->x = player()->updated_x;
		player()->y = player()->updated_y;
		player()->flage_walk = 0;
		iterate_for_render_c();
	}
}

int	update_frame(void)
{
	static unsigned int	curr_frame;
	static int			i;

	if (curr_frame % 8000 == 0 && elements()->colictable == 0)
		animate_th_hole(&i);
	else if (elements()->colictable
		&& !(player()->y == player_dir()->h_pos[1]
			&& player()->x == player_dir()->h_pos[0]))
		mlx_put_image_to_window(box()->mlx,
			box()->win, player_dir()->exit_hole[0],
			player_dir()->h_pos[0] * 32 + 2,
			player_dir()->h_pos[1] * 32 + 4);
	set_player_nd_colictables(curr_frame);
	if (curr_frame % 9000 == 0)
		iterate_for_render_x();
	curr_frame++;
	re_check_enemy();
	if (box()->map[player()->updated_y][player()->updated_x] == 'E'
		&& elements()->colictable == 0)
		quite_nd_destroy
			("YOU WIN");
	return (0);
}

void	set_game_pos(void)
{
	int	i;
	int	l;
	int	j;

	i = 0;
	l = 0;
	while (box()->map[i])
	{
		j = 0;
		while (box()->map[i][j])
		{
			if (box()->map[i][j] == 'X')
			{
				player()->enemy_yp[l] = i;
				player()->enemy_xp[l] = j;
				l++;
			}
			j++;
		}
		i++;
	}
}
