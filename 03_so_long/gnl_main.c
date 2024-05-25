/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:52:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/25 23:31:09 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./0_LIBFT/libft.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(av[ac-1], O_RDONLY);
	line = get_next_line(fd);
	ft_printf("%p\n", line);
	while (line)
	{
		ft_printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
