/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:01 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/23 15:30:11 by  mel-mouh        ###   ########.fr       */
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

void	print_data(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		printf("\nline %d:\n\t[%s]", i, data[i]);
		i++;
	}
	printf("\n");
}

void	map_validation_error(void)
{
	ft_putstr_fd("\t\t\t\t\tError\n", 2);
	ft_putstr_fd("\t\t\t\tInvalid map detected!\n", 2);
	ft_putstr_fd("\tPlease ensure the map is properly ", 2);
	ft_putstr_fd("formatted and follows all validation rules.\n", 2);
}

int	check_walls(char *data_map, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		while (data_map[i])
		{
			if (data_map[i] != '1')
			{
				map_validation_error();
				return (0);
			}
			i++;
		}
	}
	else
	{
		if (data_map[0] != '1' || data_map[ft_strlen(data_map) - 1] != '1')
		{
			map_validation_error();
			return (0);
		}
	}
	return (1);
}

int	check_lenght(char **map)
{
	int		i;
	size_t	lenght;

	i = 0;
	lenght = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != lenght)
			return (0);
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
		map_validation_error();
		ft_free(map);
		close(fd);
		exit(1);
	}
	while (map[i])
	{
		if (!check_walls(map[i], i))
		{
			map_validation_error();
			ft_free(map);
			close(fd);
			exit (1);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int		map_fd;
	char	**data_file;

	if (ac < 2)
		return (ft_putendl_fd("syntax error: ./so_long <path/to/file/map>", 2), 1);
	map_fd = safer_open(av[1]);
	data_file = data_splited(data_file_parser(map_fd));
	if (!data_file)
	{
		close(map_fd);
		perror("malloc :");
		return (1);
	}
	iterate_on_map(data_file, map_fd);
	print_data(data_file);
	ft_free(data_file);
	return (0);
}