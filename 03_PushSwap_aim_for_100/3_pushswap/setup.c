/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:30:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 03:43:25 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// will add a new node to the end of the list
// if list doesn't exist, will create it
static
int	*extend(int *buffer, int buffer_len, int value, int fd)
{
	int	*result;
	int	cursor;

	if (!buffer)
	{
		result = malloc(sizeof(int));
		if (!result)
			error(NULL, fd);
		*result = value;
		return (result);
	}
	result = malloc((buffer_len + 1) * sizeof(int));
	if (!result)
	{
		free(buffer);
		error(NULL, fd);
	}
	cursor = -1;
	while (cursor++ < buffer_len - 1)
		*(result + cursor) = *(buffer + cursor);
	*(result + cursor) = value;
	return (free(buffer), result);
}

// creates chained list from given and validated arguments
static
t_list	*setup_multiple(int argc, char **argv, int fd)
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
			ft_atoi_prime(*(argv + csr_argc) + csr_argv, &csr_argv), fd);
		else
			csr_argv++;
	}
	result = create(buffer, buffer_len);
	return (free(buffer), result);
}

// creates chained list from given and validated arguments
static
t_list	*setup_single(char **argv, int fd)
{
	int		*buffer;
	int		buffer_len;
	int		csr_argv;
	int		len;
	t_list	*result;

	buffer = NULL;
	buffer_len = 0;
	csr_argv = 0;
	len = ft_strlen(argv[1]);
	while (csr_argv < len)
	{
		if (*(argv[1] + csr_argv) != ' ')
			buffer = extend(buffer, buffer_len++, \
			ft_atoi_prime(argv[1] + csr_argv, &csr_argv), fd);
		else
			csr_argv++;
	}
	result = create(buffer, buffer_len);
	return (free(buffer), result);
}

// creates chained list from given and validated arguments
t_list	*setup(int argc, char **argv, int fd)
{
	if (argc == 2)
		return (setup_single(argv, fd));
	else
		return (setup_multiple(argc, argv, fd));
}
