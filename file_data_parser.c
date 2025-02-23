/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:56:46 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/23 13:58:47 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

char	*data_file_parser(int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	temp = NULL;
	while (line)
	{
		temp = ft_gnlstrjoin(temp, line);
		free(line);
		line = get_next_line(fd);
	}
	return (temp);
}

char **data_splited(char *data_file)
{
	char **data_splited;

	data_splited = ft_split(data_file, '\n');
	free(data_file);
	return (data_splited);
}
