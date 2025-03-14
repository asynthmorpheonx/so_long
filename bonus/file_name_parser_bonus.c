/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:23:00 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/03/13 00:32:33 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_some_errors(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

static size_t	extract_th_extension(char *file_path)
{
	return (ft_strlen(file_path) - 4);
}

static void	unsupported_file_handler(char *file_path)
{
	ft_putstr_fd("Error: Unsupported file format\n", 2);
	ft_putstr_fd("The provided file ", 2);
	ft_putstr_fd("\"", 2);
	ft_putstr_fd(file_path, 2);
	ft_putstr_fd("\"", 2);
	ft_putstr_fd(" must have a '.ber' extension.\n", 2);
	exit (1);
}

static void	validate_if_its_readable(int fd, char *file_path)
{
	char	buffer[1];
	ssize_t	read_byts;

	read_byts = read(fd, buffer, 0);
	if (read_byts == -1)
	{
		close(fd);
		print_some_errors(file_path);
		exit(1);
	}
}

int	safer_open(char *file_path)
{
	int	fd;

	if (ft_strncmp(file_path + extract_th_extension(file_path), ".ber", 4))
		unsupported_file_handler(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		print_some_errors(file_path);
		exit (1);
	}
	validate_if_its_readable(fd, file_path);
	return (fd);
}
