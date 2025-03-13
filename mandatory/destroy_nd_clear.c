/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_nd_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:17:40 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/11 03:18:32 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

int	quite_nd_destroy(void)
{
	ft_printf("you quite the game\n");
	start_clear(0);
	return (0);
}

void	destroy_wall(void)
{
	if (wall()->floor)
		mlx_destroy_image(box()->mlx, wall()->floor);
	if (wall()->left)
		mlx_destroy_image(box()->mlx, wall()->left);
	if (wall()->normal)
		mlx_destroy_image(box()->mlx, wall()->normal);
	if (wall()->right)
		mlx_destroy_image(box()->mlx, wall()->right);
	if (wall()->tleft)
		mlx_destroy_image(box()->mlx, wall()->tleft);
	if (wall()->tright)
		mlx_destroy_image(box()->mlx, wall()->tright);
	if (wall()->top)
		mlx_destroy_image(box()->mlx, wall()->top);
	if (wall()->sea)
		mlx_destroy_image(box()->mlx, wall()->sea);
	if (player_dir()->rframe)
		mlx_destroy_image(box()->mlx, player_dir()->rframe);
	if (player_dir()->colictable)
		mlx_destroy_image(box()->mlx, player_dir()->colictable);
}

void	start_clear(int z)
{
	int	i;

	i = 0;
	destroy_wall();
	while (i < 5)
	{
		if (player_dir()->exit_hole[i])
			mlx_destroy_image(box()->mlx, player_dir()->exit_hole[i]);
		i++;
	}
	ft_free(box()->map);
	mlx_destroy_window(box()->mlx, box()->win);
	mlx_destroy_display(box()->mlx);
	free(box()->mlx);
	exit (z);
}
