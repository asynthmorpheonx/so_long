/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:48:21 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 23:35:21 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(int x, int y, char **map)
{
	if (map[y][x] != '0' && map[y][x]
		!= 'C' && map[y][x] != 'E' && map[y][x] != 'P')
		return ;
	map[y][x] = 'V';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C'
		|| map[y - 1][x] == 'E' || map[y - 1][x] == 'P')
		flood_fill(x, y - 1, map);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C'
		|| map[y + 1][x] == 'E' || map[y + 1][x] == 'P')
		flood_fill(x, y + 1, map);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C'
		|| map[y][x + 1] == 'E' || map[y][x + 1] == 'P')
		flood_fill(x + 1, y, map);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C'
		|| map[y][x - 1] == 'E' || map[y][x - 1] == 'P')
		flood_fill(x - 1, y, map);
}

int	check_all_colictable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				ft_free(map);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_free(map);
	return (1);
}

char	**mapdup(char **map)
{
	int		i;
	char	**dup;

	i = 0;
	while (map[i])
		i++;
	dup = malloc((i + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
