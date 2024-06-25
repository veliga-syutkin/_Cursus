/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:38:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 20:35:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
  Function to move player in the map and store it's new position.
dir = direction of the movement, unless it's a wall:
DIR_DOWN (1) = down
DIR_LEFT (2) = left
DIR_UP (3) = up
DIR_RIGHT (4) = right
And returns player's new position.
-----
	If direction points to a wall, returns NULL.
	If direction is NULL, returns player's current position.
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

	if (dir && dir != -1)
		last = dir;
	return (last);
}

/*
  Increases turn count with argument TRUE,
and returns total value in any case
*/
int	turns(bool count)
{
	static int	turns;

	if (count)
		turns++;
	return (turns);
}

/*
  Function to display player, at the beginning, after every move,
and after taking each collectible.
*/
int	display_player(mlx_t *mlx, t_txtr *images, t_map *player)
{
	int				xy[2];
	static int		r_value;
	static t_txtr	*s_images;
	mlx_image_t		*show_player;

	if (!s_images)
	{
		s_images = images;
	}
	if (mlx && images)
	{
		xy[0] = player->xy[0] * 128;
		xy[1] = player->xy[1] * 128;
		r_value = (mlx_image_to_window(mlx, images->player, xy[0], xy[1]));
	}
	if (player)
	{
		show_player = s_images->player;
		xy[0] = 128 * (player->xy[0]);
		xy[1] = 128 * (player->xy[1]);
		show_player->instances[0].x = xy[0];
		show_player->instances[0].y = xy[1];
	}
	return (r_value);
}
