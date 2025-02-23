/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:01 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/23 15:44:06 by  mel-mouh        ###   ########.fr       */
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