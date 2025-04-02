/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:18:02 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/02 22:27:21 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_string_to_ascii_per_char(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		printf("%02d ", str[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int	cursor;

	cursor = 0;
	if (argc < 2)
		return (0);
	while (argv[++cursor])
		print_string_to_ascii_per_char(argv[cursor], strlen(argv[cursor]));
	return (0);
}
