/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:24:19 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 17:03:27 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	grid_len(t_map *map_grid, t_allocs **allocs)
{
	int		len;
	t_map	*cursor;

	len = 0;
	cursor = map_grid;
	while (cursor)
	{
		len++;
		cursor = cursor->right;
	}
	if (!map_grid->down)
		return (len);
	else if (grid_len(map_grid->down, allocs) != len || len > 1920 / 128)
	{
		if (grid_len(map_grid->down, allocs) != len)
			ft_error(ERR_MAP_CONTENT, allocs);
		else if (len > 1920 / 128)
			ft_error(ERR_MAP_BIG, allocs);
	}
	return (len);
}

int	grid_height(t_map *map_grid, t_allocs **allocs)
{
	int		height;
	t_map	*cursor;

	height = 0;
	cursor = map_grid;
	while (cursor)
	{
		height++;
		cursor = cursor->down;
	}
	if (!map_grid->right)
		return (height);
	else if (grid_height(map_grid->right, allocs) != height || height > 8)
	{
		if (grid_height(map_grid->right, allocs) != height)
			ft_error(ERR_MAP_CONTENT, allocs);
		else if (height > 1024 / 128)
			ft_error(ERR_MAP_BIG, allocs);
	}
	return (height);
}

/*
	Counts and returns the number of cells with specific item.
*/
int	content_check(int item, t_map *map_grid)
{
	int		x;
	t_map	*cursor;

	cursor = map_grid;
	x = 0;
	while (cursor)
	{
		if (cursor->content == item)
			x++;
		if (cursor->right)
			cursor = cursor->right;
		else
		{
			while (cursor && cursor->left)
				cursor = cursor->left;
			cursor = cursor->down;
		}
	}
	return (x);
}

/*
  Checks if map has exactly 1 player, exactly 1 exit and at least 1 collectible.
*/
void	inner_check(t_map *map_grid, t_allocs **allocs)
{
	t_map	*cursor;

	cursor = map_grid;
	if (content_check(PLAYER, map_grid) != 1)
		ft_error(ERR_MAP_CONTENT, allocs);
	if (content_check(EXIT, map_grid) != 1)
		ft_error(ERR_MAP_CONTENT, allocs);
	if (content_check(COLLECTIBLE, map_grid) < 1)
		ft_error(ERR_MAP_CONTENT, allocs);
	while (cursor)
	{
		if (!(cursor->content == '1' || cursor->content == '0' \
			|| cursor->content == 'P' || cursor->content == 'C' \
			|| cursor->content == 'E'))
			ft_error(ERR_MAP_CONTENT, allocs);
		if (cursor->right)
			cursor = cursor->right;
		else
		{
			while (cursor && cursor->left)
				cursor = cursor->left;
			cursor = cursor->down;
		}
	}
}

/*
  Checks the map for rectangular shape,
  for inner content,
  for the outer wall,
  for the solvable path.
*/
void	check_map(t_map *map_grid, t_allocs **allocs)
{
	grid_len(map_grid, allocs);
	grid_height(map_grid, allocs);
	inner_check(map_grid, allocs);
	outer_check(map_grid, allocs);
	path_check(map_grid, allocs);
}
