/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:31:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/01 01:33:37 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/* Checks input for allowed signs: space before single '+' or '-' */
static
int	char_allowed_sign(char **c, int cursor_c, int cursor_v)
{
	char	*buffer;

	buffer = *(c + cursor_c) + cursor_v;
	if (*buffer == '-' || *buffer == '+')
	{
		if (*(buffer + 1) == '-' || *(buffer + 1) == '+')
			error(NULL);
		if (cursor_v)
			if (*(buffer - 1) != ' ')
				error(NULL);
		return (1);
	}
	return (0);
}

// Checks input for allowed signs: '0' to '9'
static int	char_allowed(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	error(NULL);
	return (false);
}

// Looks for presence of integer overflow, if yes: exit with error
static void	check_max(char *number)
{
	if (ft_atol(number) > INT_MAX)
		error(NULL);
}

// Looks for presence of integer overflow.
static void	check_number(int argc, char **argv)
{
	int	csr_argc;

	csr_argc = 1;
	while (csr_argc < argc)
	{
		if (ft_strlen(*(argv + csr_argc++)) > 11)
			error(NULL);
		if (ft_strlen(*(argv + csr_argc - 1)) == 10)
			check_max(*(argv + csr_argc - 1));
	}
}

// Process input for validity of data provided.
// DEPRECATED: Must be multiple arguments (e.g.: ./push_swap 1 2 3 4 5)
void	check(int argc, char **argv)
{
	int		csr_argc;
	int		csr_argv;

	csr_argc = 1;
	csr_argv = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		return (dquote(argv));
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
			error(NULL);
	}
	check_number(argc, argv);
}
