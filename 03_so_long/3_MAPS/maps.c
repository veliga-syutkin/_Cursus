/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:33:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/21 08:30:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(char *map)
{
	int		fd;
	char	*line;
	t_mma	**map;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error(ERR_MAP_OPEN, NULL);
	while (get_next_line(fd, &line))
	{
		map = load_map(line);
		free(line);
	}
	free(line);
	close(fd);
}

t_map	**load_map(const char *line)
{
	t_map		*map;
	int			cursor;
	static int	y;
	static int	len_first_line;

	if (y == 0)
		len_first_line = ft_strlen(line);
	if (len_first_line != ft_strlen(line))
		ft_error(ERR_MAP_CONTENT, NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error(ERR_ALLOC, NULL);
	cursor = 0;
	while (line[cursor])
	{
		map->content = line[cursor];
		map->xy[0] = cursor;
		map->xy[1] = y;
		map->path_check = false;
		cursor++;
	}
	return (&map);
}

void	check_map_extension(int argc, char **argv)
{
	int		cursor;

	cursor = ft_strlen(argv[1]);
	if (argv[1][cursor - 1] != 'r'
		|| argv[1][cursor - 2] != 'e'
		|| argv[1][cursor - 3] != 'b'
		|| argv[1][cursor - 4] != '.')
	{
		ft_error(ERR_MAP_EXTENSION, NULL);
	}
}

void	map(int argc, char **argv)
{
	if (argc != 2)
		ft_error(ERR_MAP_PATH, NULL);
	check_map_extension(argc, argv);
	read_map(argv[1]);
}
