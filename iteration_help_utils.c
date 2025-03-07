/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_help_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:35:29 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/07 02:55:04 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_if_error(int i, char **map)
{
	static int err;

	if (!err)
	{
		err++;
		ft_putstr_fd("Error\n", 2);
	}
	if (i == 0)
		ft_putstr_fd("The map must contain atleast one colictable\n", 2);
	else if (i == 1)
		ft_putstr_fd("The map must contain exactly one player\n", 2);
	else if (i == 2)
		ft_putstr_fd("The map must contain exactly one exit\n", 2);
	else if (i == 3)
		ft_putstr_fd("Invalid character found in the map\n", 2);
	else if (i == 4)
		ft_putstr_fd("The map must contain atleast one one enemy\n", 2);
	ft_free(map);
	exit(1);
}

int	check_element(char **map)
{
	if (!elements()->colictable)
		print_if_error(0, map);
	if (elements()->map_exit != 1)
		print_if_error(2, map);
	if (elements()->others != 0)
		print_if_error(3, map);
	if (elements()->player != 1)
		print_if_error(1, map);
	if (!elements()->enemy)
		print_if_error(4, map);
	return (1);
}

void	check_for_elements(char **map)
{
	int			i;
	int			j;

	i = 0;
	ft_bzero(elements(), sizeof(t_elements));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p_pos(i, j, 0);
				elements()->player += 1;
			}
			else if (map[i][j] == 'C')
				elements()->colictable += 1;
			else if (map[i][j] == 'E')
				elements()->map_exit += 1;
			else if (map[i][j] == 'X')
				elements()->enemy += 1;
			else if (map[i][j] != '1' && map[i][j] != '0')
				elements()->others += 1;
			j++;
		}
		i++;
	}
	check_element(map);
}

int	export_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}