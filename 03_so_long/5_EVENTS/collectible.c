/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:52:39 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 20:37:54 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
  Checks if the cell is collectible.
If it is, increments the counter of collected collectibles,
and changes the cell content to FLOOR.
Returns the number of collected collectibles.
*/
int	collectible(t_map *map)
{
	static int	collectible;
	mlx_image_t	*floor;
	mlx_image_t	*player;

	if (map && map->content == COLLECTIBLE)
	{
		floor = ft_images(NULL, NULL, NULL)->floor;
		player = ft_images(NULL, NULL, NULL)->player;
		collectible++;
		map->content = FLOOR;
		mlx_image_to_window(address_mlx(NULL), floor, \
			128 * (map->xy[0]), 128 * (map->xy[1]));
		mlx_set_instance_depth(&(player->instances[0]), \
			(floor->instances[floor->count - 1].z) + 1);
		ft_printf("Collected: %d\n", collectible);
	}
	return (collectible);
}

/*
  If all collectibles are collected, returns true, else returns false.
*/
bool	all_collected(void)
{
	t_map	*map;

	map = address_map(NULL);
	if (content_check(COLLECTIBLE, map) == 0)
		return (true);
	return (false);
}
