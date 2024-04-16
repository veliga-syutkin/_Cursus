/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:31:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/15 15:39:07 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdio.h>

/* Checks input for allowed signs: space before single '+' or '-' */
static
int	char_allowed_sign(char **argv, int cursor_c, int cursor_v)
{
	if (ft_isdigit(argv[cursor_c][cursor_v]) || argv[cursor_c][cursor_v] == ' ')
		return (true);
	else if (argv[cursor_c][cursor_v] == '-' || argv[cursor_c][cursor_v] == '+')
	{
		if (!ft_isdigit(argv[cursor_c][cursor_v + 1]))
			error(NULL);
		if (cursor_v)
			if (argv[cursor_c][cursor_v - 1] != ' ')
				error(NULL);
		return (true);
	}
	return (false);
}

// // Checks input for allowed signs: '0' to '9'
// static int	char_allowed(int c)
// {
// 	if ((c >= '0' && c <= '9') || c == ' ' || c == '-' || c == '+')
// 		return (true);
// 	error(NULL);
// 	return (false);
// }

// Looks for presence of integer overflow, if yes: exit with error
static bool	check_max(char *number)
{
	int	lenght;

	if (ft_strlen(number) < 1)
		error(NULL);
	lenght = 0;
	if ((number[lenght]) == '-' \
		|| (number[lenght]) == '+')
		lenght++;
	while (*number == '0')
		number++;
	while (ft_isdigit(number[lenght]))
		lenght++;
	if (lenght > 11 && ft_atol(number) != 0)
		error(NULL);
	if (ft_atol(number) <= INT_MAX && ft_atol(number) >= INT_MIN)
		return (true);
	return (error(NULL), false);
}

// Looks for presence of integer overflow.
static void	check_number(int argc, char **argv)
{
	int	csr_argc;
	int	csr_argv;

	csr_argc = 1;
	csr_argv = 0;
	while (csr_argc < argc)
	{
		if (csr_argv == 0)
			check_max(&argv[csr_argc][csr_argv]);
		if (argv[csr_argc][csr_argv] == ' ' && argv[csr_argc][csr_argv + 1])
			check_max(&argv[csr_argc][csr_argv]);
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
// void	check(int argc, char **argv)
// {
// 	int		csr_argc;
// 	int		csr_argv;

// 	csr_argc = 1;
// 	csr_argv = 0;
// 	if (argc == 1)
// 		exit(0);
// 	// if (argc == 2)
// 	// 	return (dquote(argv));
// 	while (csr_argc < argc)
// 	{
// 		if (!*(*(argv + csr_argc) + csr_argv))
// 		{
// 			csr_argv = 0;
// 			csr_argc++;
// 		}
// 		else if (char_allowed(*(*(argv + csr_argc) + csr_argv)))
// 			csr_argv++;
// 		else if (char_allowed_sign(argv, csr_argc, csr_argv))
// 			csr_argv++;
// 		else
// 			error(NULL);
// 	}
// 	check_number(argc, argv);
// }


void	check(int argc, char **argv)
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
			error(NULL);
		if (!argv[csr_argc][csr_argv])
		{
			csr_argv = 0;
			csr_argc++;
		}
		else if (char_allowed_sign(argv, csr_argc, csr_argv))
			csr_argv++;
		else
			error(NULL);
	}
	check_number(argc, argv);
}
