/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:14:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/23 18:02:14 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	vertical_fix(t_map **map, t_map *cell_start)
{
	t_map	*cursor_1;
	t_map	*cursor_2;

	if (!cell_start)
		return ;
	cursor_1 = cell_start;
	cursor_2 = cursor_1->down;
	while (cursor_1 && cursor_2)
	{
		if (cursor_1->xy[0] == cursor_2->xy[0])
		{
			cursor_1->down = cursor_2;
			cursor_2->top = cursor_1;
		}
		cursor_1 = cursor_1->right;
		cursor_2 = cursor_1->right;
	}
	vertical_fix(map, cell_start->down);
}

t_map	*find_cell(t_map **map, int cell_x, int cell_y)
{
	t_map	*temp;

	temp = *map;
	while (temp)
	{
		while (temp && temp->xy[1] != cell_y)
			temp = temp->down;
		while (temp && temp->xy[0] != cell_x)
			temp = temp->left;
	}
	return (temp);
}

void	grid_fix(t_map **map, t_allocs **allocs)
{
	t_allocs	*cursor;
	t_map		*cursor_map;

	cursor = get_id(allocs, "top_left");
	cursor_map = *map;
	while (cursor->id == "somewhere")
	{
		if (((t_map *)(cursor->content))->xy[1] !=
			((t_map *)(cursor->next->content))->xy[1])
		{
			cursor_map->down = (((t_map *)(cursor->next->content))->xy[1]);
			cursor_map = cursor_map->down;
		}
		cursor = cursor->next;
	}
	vertical_fix(map, *map);
}
