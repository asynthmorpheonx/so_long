/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:12:56 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 19:31:42 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_move_handle(int y, int x, int flag, void	*p_img)
{
	if (box()->map[player()->updated_y + y][player()->updated_x + x] != '1')
	{
		player_moves()->move_count++;
		ft_printf("move count: %d\n", player_moves()->move_count);
		player()->updated_y = player()->updated_y + y;
		player()->updated_x = player()->updated_x + x;
		p_pos(player()->updated_y, player()->updated_x, flag);
	}
	box()->p_status = p_img;
}

int	update_player_pos(int kcode)
{
	if (ESC_CODE == kcode)
		quite_nd_destroy("you quit the game bae");
	else if (D_CLICK == kcode)
		player_move_handle(0, 1, 1, player_dir()->rframe);
	else if (A_CLICK == kcode)
		player_move_handle(0, -1, 1, player_dir()->lframe);
	else if (W_CLICK == kcode)
		player_move_handle(-1, 0, 1, player_dir()->tframe);
	else if (S_CLICK == kcode)
		player_move_handle(1, 0, 1, player_dir()->rframe);
	if (box()->map[player()->updated_y][player()->updated_x] == 'C')
	{
		box()->map[player()->updated_y][player()->updated_x] = '0';
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->floor,
			player()->updated_x * 32 + 2, player()->updated_y * 32 + 4);
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

void	re_check_enemy(void)
{
	int	j;

	j = 0;
	while (j < elements()->enemy)
	{
		if ((player()->updated_x == player()->enemy_xp[j])
			&& (player()->updated_y == player()->enemy_yp[j]))
			quite_nd_destroy
				("What A Loser");
		j++;
	}
}

void	update_enemy_pos(void)
{
	int	i;
	int	next_x;

	i = 0;
	while (i < elements()->enemy)
	{
		if (box()->map[player()->enemy_yp[i]]
			[player()->enemy_xp[i] + player()->enemy_direction] != '0')
			player()->enemy_direction *= -1;
		i++;
	}
	i = 0;
	while (i < elements()->enemy)
	{
		next_x = player()->enemy_xp[i] + player()->enemy_direction;
		if (box()->map[player()->enemy_yp[i]][next_x] == '0')
		{
			box()->map[player()->enemy_yp[i]][player()->enemy_xp[i]] = '0';
			box()->map[player()->enemy_yp[i]][next_x] = 'X';
			player()->enemy_xp[i] = next_x;
		}
		else
			player()->enemy_direction *= -1;
		i++;
	}
}
