/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_realease.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mouh <mel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:03:43 by mel-mouh          #+#    #+#             */
/*   Updated: 2025/03/07 18:17:03 by mel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_long.h"

t_elements	*elements()
{
	static	t_elements pp;

	return (&pp);
}	

t_player	*player()
{
	static t_player	pp;

	return (&pp);
}

t_box	*box()
{
	static t_box	pp;
	
	return(&pp);
}

t_plate	*wall()
{
	static t_plate pp;
	
	return (&pp);
}

t_anime	*player_dir()
{
	static	t_anime pp;
	
	return (&pp);
}

t_movement	*player_moves()
{
	static	t_movement pp;

	return (&pp);
}