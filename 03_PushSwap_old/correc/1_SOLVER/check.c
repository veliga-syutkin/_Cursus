/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:31:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/18 02:28:10 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks input for allowed signs: space before single '+' or '-' */
static
int	char_allowed_sign(char **c, int cursor_c, int cursor_v)
{
	char	*buffer;

	buffer = *(c + cursor_c) + cursor_v;
	if (*buffer == '-' || *buffer == '+')
	{
		if (*(buffer + 1) == '-' || *(buffer + 1) == '+')
			error();
		if (cursor_v)
			if (*(buffer - 1) != ' ')
				error();
		return (1);
	}
	return (0);
}

// Checks input for allowed signs: '0' to '9'
static int	char_allowed(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Looks for presence of integer overflow, if yes: exit with error
static void	check_max(char *number)
{
	int	useless;

	useless = 0;
	if (ft_atoi_long(number, &useless) > 2147483647)
		error();
}

// Looks for presence of integer overflow.
static void	check_number(int argc, char **argv)
{
	int	csr_argc;

	csr_argc = 1;
	while (csr_argc < argc)
	{
		if (ft_strlen(*(argv + csr_argc++)) > 10)
			error();
		if (ft_strlen(*(argv + csr_argc - 1)) == 10)
			check_max(*(argv + csr_argc - 1));
	}
}

// Process input for validity of data provided.
// Must be multiple arguments (e.g.: ./push_swap 1 2 3 4 5)
void	check(int argc, char **argv)
{
	int		csr_argc;
	int		csr_argv;

	csr_argc = 1;
	csr_argv = 0;
	while (csr_argc < argc)
	{
		if (!*(*(argv + csr_argc) + csr_argv))
		{
			csr_argv = 0;
			csr_argc++;
		}
		else if (char_allowed(*(*(argv + csr_argc) + csr_argv)))
			csr_argv++;
		else if (char_allowed_sign(argv, csr_argc, csr_argv))
			csr_argv++;
		else
			error();
	}
	if (argc == 1)
		exit(0);
	check_number(argc, argv);
}
