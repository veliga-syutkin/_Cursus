/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-09 04:52:39 by vsyutkin          #+#    #+#             */
/*   Updated: 2024-06-09 04:52:39 by vsyutkin         ###   ########.fr       */
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

	if (map && map->content == COLLECTIBLE)
	{
		collectible++;
		map->content = FLOOR;
		ft_printf("Collected: %d\n", collectible);
	}
	return (collectible);
}

/*
If all collectibles are collected, returns true, else returns false.
*/
bool	all_collected(t_map *map)
{
	static int	max;

	if (!max)
		max = content_check(COLLECTIBLE, map);
	if (collectible(map) == max)
		return (true);
	return (false);
}
