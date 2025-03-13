/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boxes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:19:02 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 00:32:33 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_wall(void)
{
	if (!wall()->floor || !wall()->img_sea
		|| !wall()->img_tleft || !wall()->img_tright
		|| !wall()->img_normal || !wall()->img_right
		|| !wall()->img_left || !wall()->img_top)
	{
		ft_putstr_fd("Error\n", 2);
		start_clear(1);
	}
}

void	check_frames(void)
{
	if (!player_dir()->lframe
		|| !player_dir()->rframe || !player_dir()->tframe)
	{
		ft_putstr_fd("Error\n", 2);
		start_clear(1);
	}
}

void	check_colictables(void)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		if (!((player_dir()->colictable)[i]))
		{
			ft_putstr_fd("Error\n", 2);
			start_clear(1);
		}
		i++;
	}
}

void	check_exits(void)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (!((player_dir()->exit_hole)[i]))
		{
			ft_putstr_fd("Error\n", 2);
			start_clear(1);
		}
		i++;
	}
}

void	check_counter(void)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		if (!((player_moves()->nbrs)[i]))
			start_clear(1);
		i++;
	}
}
