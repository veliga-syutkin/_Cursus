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
Function to move player in the map and store it's current position.
dir = direction of the movement, unless it's a wall:
DIR_DOWN (1) = down
DIR_LEFT (2) = left
DIR_UP (3) = up
DIR_RIGHT (4) = right
And returns player's new position.
-----
	If direction points to a wall, returns NULL.
*/
t_map	*player(t_map *map, int dir)
{
	static t_map	*player;

	(void)last_dir(dir);
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

/*
	Returns last direction of the player.
	Stores if dir not NULL before. 
*/
int	last_dir(int dir)
{
	static int	last;

	if (!dir && dir != -1)
		last = dir;
	return (last);
}

/*
Increases turn count with argument TRUE,
and returns total value in any case*/
int	turns(bool count)
{
	static int	turns;

	if (count)
		turns++;
	return (turns);
}
