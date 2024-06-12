/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-11 23:37:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2024-06-11 23:37:54 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
  When player cross the exit, checks if all collectibles are collected.
  If they are, player wins.
  If they are not, player gets a notification 
that they have to collect all collectibles.
  Returns true when win.
*/
bool	exit_game(t_map *map)
{
	if (map->content == EXIT)
	{
		if (all_collected(map))
			return (true);
		else
			message(MSG_EXIT_CLOSED);
	}
	return (false);
}
