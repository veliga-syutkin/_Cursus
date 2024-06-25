/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:33:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 17:54:16 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
  Looks if map file extension is .ber
*/
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

/*
  Loads map from file to grid
*/
void	load_map(char *line, t_map **map_grid, t_allocs **allocs)
{
	int			column;
	static int	line_number;
	t_map		*cell_on_left;

	column = 0;
	if (line[column] == '\n')
		return (free(line), ft_error(ERR_MAP_CONTENT, allocs));
	if (!*map_grid)
	{
		mhandler_add(allocs, (malloc(sizeof(t_map))), (int *)-1);
		*map_grid = (*allocs)->content;
		map_init(line[column], column, line_number, *map_grid);
		cell_on_left = *map_grid;
		column++;
	}
	while (line[column] && line[column] != '\n')
	{
		cell_on_left = get_last(allocs)->content;
		mhandler_add(allocs, (malloc(sizeof(t_map))), (int *)-2);
		if (column)
			cell_on_left->right = get_last(allocs)->content;
		map_init(line[column], column, line_number, get_last(allocs)->content);
		column++;
	}
	line_number++;
}

/*
  Checks map path, map file, loads map and checks it.
*/
void	map(int argc, char **argv, t_map **map_grid, t_allocs **allocs)
{
	if (argc != 2)
		ft_error(ERR_MAP_PATH, NULL);
	check_map_extension(argc, argv);
	read_map(argv[1], map_grid, allocs);
	check_map(*map_grid, allocs);
}

/*
  Initializes map cell
*/
void	map_init(int content, int x, int y, t_map *map_cell)
{
	map_cell->content = content;
	map_cell->xy[0] = x;
	map_cell->xy[1] = y;
	map_cell->path_check = false;
	map_cell->top = NULL;
	map_cell->down = NULL;
	map_cell->left = NULL;
	map_cell->right = NULL;
}

/*
  Reads and stores map from file
*/
void	read_map(char *map, t_map **map_grid, t_allocs **allocs)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error(ERR_MAP_OPEN, NULL);
	line = get_next_line(fd);
	if (!line)
		ft_error(ERR_MAP_CONTENT, NULL);
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
