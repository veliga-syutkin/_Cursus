/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:21 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 10:30:18 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	dquote(char **argv)
{
	int	csr_argv;
	int	len;

	csr_argv = 0;
	len = ft_strlen(argv[1]);
	while (csr_argv < len)
	{
		if (argv[1][csr_argv] == ' ')
		{
			if (!ft_isdigit(argv[1][csr_argv + 1]) \
				&& argv[1][csr_argv + 1] != '+' \
				&& argv[1][csr_argv + 1] != '-')
				error(NULL);
		}
		if (!ft_isdigit(argv[1][csr_argv]))
			error(NULL);
		if (ft_atol(argv[1]) > INT_MAX)
			error(NULL);
		csr_argv++;
		while (argv[1][csr_argv] != ' ' && argv[1][csr_argv] != '\0')
			csr_argv++;
	}
}
