/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:40:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 01:43:03 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char *str = NULL;
		printf("PRINTF_SYS: %s,%p %d\n", /*atoi*/(argv[argc - 1]), str, 42);
		fflush(NULL);
		ft_printf("PRINTF_FT_: %s,%p %d\n", /*atoi*/(argv[argc - 1]), str, 42);
	}
	return (0);
}
