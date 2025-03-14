/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:33:11 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/14 23:50:58 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

void	user_run(int y, int x, int w_flag)
{
	player()->move_count++;
	ft_printf("move count: %d\n", player()->move_count);
	p_pos(y, x, w_flag);
}

void	check_coin(void)
{
	if (box()->map[player()->updated_y][player()->updated_x] == 'C')
	{
		box()->map[player()->updated_y][player()->updated_x] = '0';
		mlx_put_image_to_window(box()->mlx, box()->win, wall()->floor,
			player()->updated_x * 32 + 2, player()->updated_y * 32 + 4);
		elements()->colictable--;
	}
}

int	update_player_pos(int kcode)
{
	if (ESC_CODE == kcode)
		quite_nd_destroy();
	else if (D_CLICK == kcode)
	{
		if (box()->map[player()->updated_y][player()->updated_x + 1] != '1')
			user_run(player()->updated_y, ++player()->updated_x, 1);
	}
	else if (A_CLICK == kcode)
	{
		if (box()->map[player()->updated_y][player()->updated_x - 1] != '1')
			user_run(player()->updated_y, --player()->updated_x, 1);
	}
	else if (W_CLICK == kcode)
	{
		if (box()->map[player()->updated_y - 1][player()->updated_x] != '1')
			user_run(--player()->updated_y, player()->updated_x, 1);
	}
	else if (S_CLICK == kcode)
	{
		if (box()->map[player()->updated_y + 1][player()->updated_x] != '1')
			user_run(++player()->updated_y, player()->updated_x, 1);
	}
	check_coin();
	player()->flage_walk = 1;
	return (0);
}

int	update_frame(void)
{
	static unsigned int	curr_frame;

	if (curr_frame % 3200 == 0)
	{
		showw_exit();
		if (player()->flage_walk == 1)
			mlx_put_image_to_window(box()->mlx, box()->win, wall()->floor,
				player()->x * 32 + 2, player()->y * 32 + 4);
		spawn_player(player()->updated_x, player()->updated_y);
		player()->x = player()->updated_x;
		player()->y = player()->updated_y;
		player()->flage_walk = 0;
		iterate_for_render();
	}
	curr_frame++;
	if (box()->map[player()->updated_y][player()->updated_x] == 'E'
		&& elements()->colictable == 0)
	{
		ft_printf("You Win\n");
		start_clear(0);
	}
	return (0);
}

void	spawn_colictables(int x, int y)
{
	mlx_put_image_to_window(box()->mlx, box()->win,
		player_dir()->colictable, x * 32 + 2, y * 32 + 4);
}
