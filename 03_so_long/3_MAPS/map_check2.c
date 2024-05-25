/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:50:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/25 18:24:13 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*goto_exit(t_map *map_grid)
{
	t_map	*cursor;

	cursor = map_grid;
	while (cursor)
	{
		if (cursor->content == EXIT)
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

void	make_path(t_map *start_cell)
{
	t_map	*cursor;

	cursor = start_cell;
	cursor->path_check = true;
	if (cursor->top && cursor->top->content != WALL)
		make_path(cursor->top);
	if (cursor->right && cursor->right->content != WALL)
		make_path(cursor->right);
	if (cursor->down && cursor->down->content != WALL)
		make_path(cursor->down);
	if (cursor->left && cursor->left->content != WALL)
		make_path(cursor->left);
}

void	path_check(t_map *map_grid, t_allocs **allocs)
{
	t_map	*cursor;

	cursor = goto_exit(map_grid);
	make_path(cursor);
}

void	collectible_path_check(t_map *map_grid, t_allocs **allocs)
{
	t_map	*cursor;

	cursor = map_grid;
	while (cursor)
	{
		if (cursor->content == COLLECTIBLE && !cursor->path_check)
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
