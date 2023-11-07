/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:40:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 10:30:14 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("PRINTF_SYS: %#X\n", atoi(argv[argc - 1]));
		fflush(NULL);
		ft_printf("PRINTF_FT_: %u\n", atoi(argv[argc - 1]));
	}
	return (0);
}
