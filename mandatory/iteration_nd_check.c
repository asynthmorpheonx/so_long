/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_nd_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:32:18 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/10 21:12:03 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

void	map_validation_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid map detected!\n", 2);
	ft_putstr_fd("Please ensure the map is properly ", 2);
	ft_putstr_fd("formatted and follows all validation rules.\n", 2);
}

int	map_row_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	check_walls(char *data_map, int j, int map_size)
{
	int	i;

	i = 0;
	if (j == 0 || j == map_size)
	{
		while (data_map[i])
		{
			if (data_map[i] != '1')
				return (map_validation_error(), 0);
			i++;
		}
	}
	else
	{
		if (data_map[0] != '1' || data_map[ft_strlen(data_map) - 1] != '1')
			return (map_validation_error(), 0);
	}
	return (1);
}

static int	check_lenght(char **map)
{
	int		i;
	size_t	lenght;

	i = 0;
	lenght = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != lenght)
			return (map_validation_error(), 0);
		i++;
	}
	return (1);
}

void	iterate_on_map(char **map)
{
	int	i;
	int	map_size;

	i = 0;
	map_size = map_row_count(map);
	if (!check_lenght(map))
	{
		ft_free(map);
		exit(1);
	}
	while (map[i])
	{
		if (!check_walls(map[i], i, map_size))
		{
			ft_free(map);
			exit (1);
		}
		i++;
	}
	check_for_elements(map);
}
