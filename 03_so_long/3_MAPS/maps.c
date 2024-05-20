/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:33:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/21 00:26:07 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap file not found\n");
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
}

// void	load_map(const char *location)
// {
//		return ;
// }