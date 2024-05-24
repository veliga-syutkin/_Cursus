/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:33:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/24 20:55:56 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(char *map, t_map **map_grid, t_allocs **allocs)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error(ERR_MAP_OPEN, NULL);
	line = get_next_line(fd);
	while (line)
	{
		load_map(line, map_grid, allocs);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	grid_fix(map_grid, allocs);
}

void	map_init(int content, int x, int y, t_map *map_cell)
{
	map_cell->content = content;
	map_cell->xy[0] = x;
	map_cell->xy[1] = y;
	map_cell->path_check = false;
}

void	load_map(const char *line, t_map **map_grid, t_allocs **allocs)
{
	int			cursor;
	static int	y;
	t_map		*cell_on_left;

	cursor = 0;
	if (!*map_grid)
	{
		mhandler_add(allocs, (malloc(sizeof(t_map))), (TOP_LEFT));
		*map_grid = (*allocs)->content;
		map_init(line[cursor], cursor, y, *map_grid);
		cell_on_left = *map_grid;
		cursor++;
	}
	while (line[cursor])
	{
		cell_on_left = get_last(allocs)->content;
		mhandler_add(allocs, (malloc(sizeof(t_map))), (SOMEWHERE));
		if (cursor)
			cell_on_left->right = get_last(allocs)->content;
		map_init(line[cursor], cursor, y, get_last(allocs)->content);
		cursor++;
	}
	y++;
}

void	check_map_extension(int argc, char **argv)
{
	int		cursor;

	cursor = ft_strlen(argv[1]);
	if (argv[argc - 1][cursor - 1] != 'r'
		|| argv[argc - 1][cursor - 2] != 'e'
		|| argv[argc - 1][cursor - 3] != 'b'
		|| argv[argc - 1][cursor - 4] != '.')
	{
		ft_error(ERR_MAP_EXTENSION, NULL);
	}
}

void	map(int argc, char **argv, t_map **map_grid, t_allocs **allocs)
{
	if (argc != 2)
		ft_error(ERR_MAP_PATH, NULL);
	check_map_extension(argc, argv);
	read_map(argv[1], map_grid, allocs);
}
