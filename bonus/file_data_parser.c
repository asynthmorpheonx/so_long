/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:56:46 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/13 20:54:49 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*data_file_parser(int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	temp = NULL;
	while (line)
	{
		temp = ft_gnl_strjoin(temp, line);
		free(line);
		line = get_next_line(fd);
	}
	return (temp);
}

char	**data_splited(char *data_file)
{
	char	**data_splited;

	if (!data_file)
		return (NULL);
	data_splited = ft_split(data_file, '\n');
	check_newlines(data_file);
	free(data_file);
	return (data_splited);
}

void	check_newlines(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			map_validation_error();
			free(map);
			exit(1);
		}
		i++;
	}
}

char	**the_parent_parser(int map_fd)
{
	char	*map;
	char	**data;

	map = data_file_parser(map_fd);
	close(map_fd);
	if (!map)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Failed to read from file, ", 2);
		ft_putstr_fd("Please ensure that the map ", 2);
		ft_putstr_fd("file is valid and accessible.\n", 2);
		exit(1);
	}
	data = data_splited(map);
	if (!data)
	{
		perror("Error\nmalloc :");
		exit (1);
	}
	iterate_on_map(data, map_fd);
	return (data);
}
