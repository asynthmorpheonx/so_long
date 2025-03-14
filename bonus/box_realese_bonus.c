/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_realease.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:03:43 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/13 00:32:33 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_elements	*elements(void)
{
	static t_elements	pp;

	return (&pp);
}

t_game	*player(void)
{
	static t_game	pp;

	return (&pp);
}

t_box	*box(void)
{
	static t_box	pp;

	return (&pp);
}

t_plate	*wall(void)
{
	static t_plate	pp;

	return (&pp);
}

t_anime	*player_dir(void)
{
	static t_anime	pp;

	return (&pp);
}
