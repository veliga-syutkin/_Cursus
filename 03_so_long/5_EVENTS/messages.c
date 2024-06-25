/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:11:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 20:37:32 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
  Function to print to terminal a message, if it is different from previous one.
*/
void	message(char *s)
{
	static char	*last;

	if (s)
	{
		if (last != s)
			ft_printf(s);
		last = s;
	}
}

/*
  Function to communicate every major event in the game.
(On collectible cell, on exit cell).
*/
void	notification(t_map *map)
{
	bool	end;

	end = false;
	if (exit_game(player(map, -1)))
		end = true;
	if (end)
		message(MSG_WON);
	else
		collectible(player(map, -1));
}
