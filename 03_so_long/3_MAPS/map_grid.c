/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:14:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/25 17:17:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_map **map)
{
	t_map	*temp;

	temp = *map;
	while (temp)
	{
		ft_printf("%c", temp->content);
		if (!temp->right)
		{
			while (temp && temp->left)
				temp = temp->left;
			temp = temp->down;
			ft_printf("\n");
		}
		else
			temp = temp->right;
	}
	ft_printf("\n");
	ft_printf("Collectibles: %d\n", content_check(COLLECTIBLE, *map));
}

void	vertical_fix(t_map *cell_start)
{
	t_map	*cursor_1;
	t_map	*cursor_2;

	if (!cell_start || !cell_start->down)
		return ;
	cursor_1 = cell_start;
	cursor_2 = cell_start->down;
	while (cursor_1 && cursor_2)
	{
		if (cursor_1->xy[0] == cursor_2->xy[0])
		{
			cursor_1->down = cursor_2;
			cursor_2->top = cursor_1;
		}
		cursor_1 = cursor_1->right;
		cursor_2 = cursor_2->right;
	}
	vertical_fix(cell_start->down);
}

void	horizontal_fix(t_map *cell_start)
{
	t_map	*cursor_1;
	t_map	*cursor_2;

	if (!cell_start || !cell_start->right)
		return ;
	cursor_1 = cell_start;
	cursor_2 = cell_start->right;
	while (cursor_1 && cursor_2)
	{
		if (cursor_1->xy[1] == cursor_2->xy[1])
		{
			cursor_1->right = cursor_2;
			cursor_2->left = cursor_1;
		}
		cursor_1 = cursor_1->right;
		cursor_2 = cursor_2->right;
	}
	horizontal_fix(cell_start->down);
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

	cursor = get_id(allocs, (int *)-1);
	cursor_map = *map;
	while ((cursor->next) && (cursor->id == (int *)-1 \
		|| cursor->id == (int *)-2))
	{
		if (((t_map *)(cursor->content))->xy[1]
			!= ((t_map *)(cursor->next->content))->xy[1])
		{
			cursor_map->down = (((t_map *)(cursor->next->content)));
			cursor_map = cursor_map->down;
		}
		cursor = cursor->next;
	}
	if (!(*map) || !(map) || !(*map)->down)
		return ;
	vertical_fix(*map);
	horizontal_fix(*map);
}
