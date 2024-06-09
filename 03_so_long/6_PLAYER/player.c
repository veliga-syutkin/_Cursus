/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-09 04:38:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2024-06-09 04:38:31 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Function to move player in the map
dir = direction of the movement, unless it's a wall:
DIR_RIGHT (0) = right
DIR_DOWN (1) = down
DIR_LEFT (2) = left
DIR_UP (3) = up
And returns player's new position.
-----
	If direction points to a wall, returns NULL.
*/
t_map	*player(t_map *map, int dir)
{
	static t_map	*player;

	if (!player)
		player = goto_item(map, PLAYER);
	if (dir == DIR_RIGHT && player->right->content != WALL)
		player = player->right;
	else if (dir == DIR_DOWN && player->down->content != WALL)
		player = player->down;
	else if (dir == DIR_LEFT && player->left->content != WALL)
		player = player->left;
	else if (dir == DIR_UP && player->top->content != WALL)
		player = player->top;
	else if (dir == DIR_RIGHT || dir == DIR_DOWN \
				|| dir == DIR_LEFT || dir == DIR_UP)
		return (NULL);
	return (player);
}
