/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:31:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 03:20:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
// #include <stdio.h> // check if usefull in this file

/* Checks input for allowed signs: space before single '+' or '-' */
static
int	char_allowed_sign(char **argv, int cursor_c, int cursor_v, int fd)
{
	if (ft_isdigit(argv[cursor_c][cursor_v]) || argv[cursor_c][cursor_v] == ' ')
		return (true);
	else if (argv[cursor_c][cursor_v] == '-' || argv[cursor_c][cursor_v] == '+')
	{
		if (!ft_isdigit(argv[cursor_c][cursor_v + 1]))
			error(NULL, fd);
		if (cursor_v)
			if (argv[cursor_c][cursor_v - 1] != ' ')
				error(NULL, fd);
		return (true);
	}
	return (false);
}

// Looks for presence of integer overflow, if yes: exit with error
static bool	check_max(char *number, int fd)
{
	int	lenght;

	if (ft_strlen(number) < 1)
		error(NULL, fd);
	lenght = 0;
	if ((number[lenght]) == '-' \
		|| (number[lenght]) == '+')
		lenght++;
	while (*number == '0')
		number++;
	while (ft_isdigit(number[lenght]))
		lenght++;
	if (lenght > 11 && ft_atol(number) != 0)
		error(NULL, fd);
	if (ft_atol(number) <= INT_MAX && ft_atol(number) >= INT_MIN)
		return (true);
	return (error(NULL, fd), false);
}

// Looks for presence of integer overflow.
static void	check_number(int argc, char **argv, int fd)
{
	int	csr_argc;
	int	csr_argv;

	csr_argc = 1;
	csr_argv = 0;
	while (csr_argc < argc)
	{
		if (csr_argv == 0)
			check_max(&argv[csr_argc][csr_argv], fd);
		if (argv[csr_argc][csr_argv] == ' ' && argv[csr_argc][csr_argv + 1])
			check_max(&argv[csr_argc][csr_argv], fd);
		if (argv[csr_argc][csr_argv] == ' ')
			csr_argv++;
		else if (argv[csr_argc][csr_argv] == '+' || \
				argv[csr_argc][csr_argv] == '-')
			csr_argv++;
		while (argv[csr_argc][csr_argv] && argv[csr_argc][csr_argv] != ' ')
			csr_argv++;
		if (!argv[csr_argc][csr_argv])
		{
			csr_argv = 0;
			csr_argc++;
		}
	}
}

// Process input for validity of data provided.
// DEPRECATED: Must be multiple arguments (e.g.: ./push_swap 1 2 3 4 5)
void	check(int argc, char **argv, int fd)
{
	int	csr_argc;
	int	csr_argv;

	csr_argc = 1;
	csr_argv = 0;
	if (argc == 1)
		exit(0);
	while (csr_argc < argc)
	{
		if (csr_argv == 0 && argv[csr_argc][csr_argv] == ' ' \
		&& (argv[csr_argc][csr_argv + 1] == '\0' || \
			argv[csr_argc][csr_argv + 1] == ' '))
			error(NULL, fd);
		if (!argv[csr_argc][csr_argv])
		{
			csr_argv = 0;
			csr_argc++;
		}
		else if (char_allowed_sign(argv, csr_argc, csr_argv, fd))
			csr_argv++;
		else
			error(NULL, fd);
	}
	check_number(argc, argv, fd);
}
