/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:50:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/25 23:21:10 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Function to find the cell with specific item in the map.
Parsing is done from left to right on each line from top to bottom.
Returns the first encountered cell with the item.
Pass next cell to start from in order to find the next one.
Returns NULL if the item is not found.
*/
t_map	*goto_item(t_map *map_grid, int item)
{
	t_map	*cursor;

	cursor = map_grid;
	while (cursor)
	{
		if (cursor->content == item)
			break ;
		if (cursor->right)
			cursor = cursor->right;
		else
		{
			while (cursor->left)
				cursor = cursor->left;
			cursor = cursor->down;
		}
	}
	return (cursor);
}

/*
  Reccursive function for checking if player, collectibles and exit
are reacheable between each other, by flooding, starting at exit.
From starting cell, sets boolean PATH_CHECK of this cell to TRUE,
then looks if cell above/right/below/left isn't a WALL 
and it's PATH_CHECK is FALSE, then reccursives on this cell.
  This way the function won't verify a cell that once was verified.
*/
void	make_path(t_map *start_cell)
{
	t_map	*cursor;

	cursor = start_cell;
	cursor->path_check = true;
	if (cursor->top && cursor->top->content != WALL
		&& !cursor->top->path_check)
		make_path(cursor->top);
	if (cursor->right && cursor->right->content != WALL
		&& !cursor->right->path_check)
		make_path(cursor->right);
	if (cursor->down && cursor->down->content != WALL
		&& !cursor->down->path_check)
		make_path(cursor->down);
	if (cursor->left && cursor->left->content != WALL
		&& !cursor->left->path_check)
		make_path(cursor->left);
}

/*
  Checks if player, collectibles and exit are reacheable between each other.
*/
void	path_check(t_map *map_grid, t_allocs **allocs)
{
	t_map	*cursor;

	cursor = goto_item(map_grid, EXIT);
	make_path(cursor);
	collectible_path_check(map_grid, allocs);
}

/*
  Checks if collectibles are reacheable from exit.
*/
void	collectible_path_check(t_map *map_grid, t_allocs **allocs)
{
	t_map	*cursor;

	cursor = map_grid;
	while (cursor)
	{
		if ((cursor->content == COLLECTIBLE
				|| cursor->content == PLAYER) && !cursor->path_check)
			ft_error(ERR_MAP_DEAD_END, allocs);
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
  Checks if map is surrounded by walls.
*/
void	outer_check(t_map *map_grid, t_allocs **allocs)
{
	short int	dir;
	t_map		*cursor;

	dir = DIR_RIGHT;
	cursor = map_grid;
	while (cursor)
	{
		if (cursor->content != WALL)
			ft_error(ERR_MAP_CONTENT, allocs);
		if (!cursor->right && dir == DIR_RIGHT)
			dir = DIR_DOWN;
		else if (!cursor->down && dir == DIR_DOWN)
			dir = DIR_LEFT;
		else if (!cursor->left && dir == DIR_LEFT)
			dir = DIR_UP;
		if (dir == DIR_RIGHT)
			cursor = cursor->right;
		else if (dir == DIR_DOWN)
			cursor = cursor->down;
		else if (dir == DIR_LEFT)
			cursor = cursor->left;
		else if (dir == DIR_UP)
			cursor = cursor->top;
	}
}
