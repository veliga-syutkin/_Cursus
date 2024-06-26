/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:30:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/18 02:34:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// will add a new node to the end of the list
// if list doesn't exist, will create it
static
int	*extend(int *buffer, int buffer_len, int value)
{
	int	*result;
	int	cursor;

	if (!buffer)
	{
		result = malloc(sizeof(int));
		if (!result)
			error();
		*result = value;
		return (result);
	}
	result = malloc((buffer_len + 1) * sizeof(int));
	if (!result)
	{
		free(buffer);
		error();
	}
	cursor = -1;
	while (cursor++ < buffer_len - 1)
		*(result + cursor) = *(buffer + cursor);
	*(result + cursor) = value;
	return (free(buffer), result);
}

// creates chained list from given and validated arguments
t_list	*setup(int argc, char **argv)
{
	int		*buffer;
	int		buffer_len;
	int		csr_argc;
	int		csr_argv;
	t_list	*result;

	buffer = NULL;
	buffer_len = 0;
	csr_argc = 1;
	csr_argv = 0;
	while (csr_argc < argc)
	{
		if (!*(*(argv + csr_argc) + csr_argv))
		{
			csr_argv = 0;
			csr_argc++;
		}
		else if (*(*(argv + csr_argc) + csr_argv) != ' ')
			buffer = extend(buffer, buffer_len++, \
			ft_atoi(*(argv + csr_argc) + csr_argv, &csr_argv));
		else
			csr_argv++;
	}
	result = create(buffer, buffer_len);
	return (free(buffer), result);
}
