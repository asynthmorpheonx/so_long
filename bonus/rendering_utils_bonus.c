/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:21:09 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 19:27:34 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_for_each_direction(int i, int j)
{
	if (box()->map[i][j - 1] == '1' && box()->map[i - 1][j] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->img_tleft, j * 32, i * 32);
	else if (box()->map[i - 1][j] == '1' && box()->map[i][j + 1] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->img_tright, j * 32, i * 32);
	else if (box()->map[i - 1][j] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->img_top, j * 32, i * 32);
	else if (box()->map[i][j + 1]
		&& box()->map[i][j + 1] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->img_right, j * 32, i * 32);
	else if (box()->map[i][j - 1] == '1')
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->img_left, j * 32, i * 32);
	else
		mlx_put_image_to_window(box()->mlx,
			box()->win, wall()->img_normal, j * 32, i * 32);
}

void	iterate_for_render_c(void)
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
	player_dir()->c_frame_index++;
}

void	iterate_for_render_x(void)
{
	int	i;
	int	j;

	i = 0;
	update_enemy_pos();
	while (box()->map[i])
	{
		j = 0;
		while (box()->map[i][j])
		{
			if (box()->map[i][j] == 'X')
				spawn_drown_zone(j, i);
			j++;
		}
		i++;
	}
}

t_movement	*player_moves(void)
{
	static t_movement	pp;

	return (&pp);
}

int	export_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
