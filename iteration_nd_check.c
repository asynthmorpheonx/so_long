/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_nd_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:32:18 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/23 15:40:50 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

static void	map_validation_error(void)
{
	ft_putstr_fd("\t\t\t\t\tError\n", 2);
	ft_putstr_fd("\t\t\t\tInvalid map detected!\n", 2);
	ft_putstr_fd("\tPlease ensure the map is properly ", 2);
	ft_putstr_fd("formatted and follows all validation rules.\n", 2);
}

static int	check_walls(char *data_map, int j)
{
	int	i;

	i = 0;
	if (j == 0)
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

void	iterate_on_map(char **map, int fd)
{
	int	i;

	i = 0;
	if (!check_lenght(map))
	{
		ft_free(map);
		close(fd);
		exit(1);
	}
	while (map[i])
	{
		if (!check_walls(map[i], i))
		{
			ft_free(map);
			close(fd);
			exit (1);
		}
		i++;
	}
}
