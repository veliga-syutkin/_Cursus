/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:27:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/04 11:28:36 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	try_buffer_without_nl(char *buffer, char **result, int fd)
{
	*result = NULL;
	if (fd < 0)
		return (0);
	if (buffer[0] && !ft_strchr(buffer, '\n'))
	{
		*result = get_from_buffer(buffer, 0);
		if (!*result)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			buffer_result;

	if (!try_buffer_without_nl(buffer, &result, fd))
		return (result);
	if (buffer[0] && ft_strchr(buffer, '\n'))
		return (get_from_buffer(buffer, 0));
	buffer_result = read(fd, buffer, BUFFER_SIZE);
	while (buffer_result > 0)
	{
		if (buffer[0] && ft_strchr(buffer, '\n'))
			return (get_from_buffer(buffer, result));
		if (buffer[0] && !ft_strchr(buffer, '\n'))
		{
			result = get_from_buffer(buffer, result);
			if (!result)
				return (result);
		}
		buffer_result = read(fd, buffer, BUFFER_SIZE);
	}
	if (buffer_result)
		return (free(result), NULL);
	return (result);
}
