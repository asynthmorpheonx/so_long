/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:01 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/22 22:13:07 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

void	print_some_errors(char *error)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

size_t	extract_th_extension(char *file_path)
{
	return (ft_strlen(file_path) - 4);
}

void	file_handler(char *file_path)
{
	ft_putstr_fd("Error: Unsupported file format\n", 2);
	ft_putstr_fd("The provided file ", 2);
	ft_putstr_fd(file_path, 2);
	ft_putstr_fd(" must have a '.ber' extension.\n", 2);
	exit (1);
}

int	safer_open(char *file_path)
{
	int	fd;

	if (ft_strncmp(file_path + extract_th_extension(file_path), ".ber", 4))
		file_handler(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		print_some_errors(file_path);
		exit (1);
	}
	return (fd);
}

int main(int ac, char **av)
{
	int	map_fd;
	if (ac < 2)
		return (ft_putendl_fd("syntax error: ./so_long maps/<some_map.ber>", 2), 1);
	map_fd = safer_open(av[1]);
}