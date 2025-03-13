/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:12:43 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/10 22:05:27 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

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
			mlx_put_image_to_window(box()->mlx,
				box()->win, wall()->sea, j, i);
			j += 32;
		}
		i += 32;
	}
}

void	render_for_each_direction(int i, int j)
{
	if (box()->map[i][j - 1] == '1' &&
	box()->map[i - 1][j] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->tleft, j * 32, i * 32);
	else if (box()->map[i - 1][j] == '1' &&
		box()->map[i][j + 1] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->tright, j * 32, i * 32);
	else if (box()->map[i - 1][j] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->top, j * 32, i * 32);
	else if (box()->map[i][j + 1] &&
	box()->map[i][j + 1] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->right, j * 32, i * 32);
	else if (box()->map[i][j - 1] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->left, j * 32, i * 32);
	else
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->normal, j * 32, i * 32);
}

void	iterate_for_render(void)
{
	int	i;
	int	j;

	i = 0;
	while (box()->map[i])
	{
		j = 0;
		while (box()->map[i][j])
		{
			if (box()->map[i][j] == 'C')
				spawn_colictables(j, i);
			j++;
		}
		i++;
	}
	player_dir()->e_frame_index++;
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

void	spawn_player(int x, int y)
{
	mlx_put_image_to_window(box()->mlx, box()->win,
		player_dir()->rframe, x * 32 + 2, y * 32 + 4);
}
