/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_loop_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:43:54 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 00:32:33 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_th_ocean(void)
{
	int	i;
	int	j;

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
