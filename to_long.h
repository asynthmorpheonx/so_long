/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mel-mouh < mel-mouh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:01:50 by  mel-mouh         #+#    #+#             */
/*   Updated: 2025/02/23 13:58:23 by  mel-mouh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_LONG_H
# define TO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <errno.h>

int		safer_open(char *file_path);
char **data_splited(char *data_file);
char	*data_file_parser(int fd);

#endif