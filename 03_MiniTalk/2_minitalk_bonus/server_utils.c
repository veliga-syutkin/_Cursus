/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 05:27:13 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/15 12:13:16 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

////////////////////////////////////////////////////////////////////////////////
				/* STATIC VARIABLES TO USE ACROSS THE PROGRAM */
////////////////////////////////////////////////////////////////////////////////

short int	ft_static(int data, int flag, int param)
{
	static char	info[3];

	if (flag == FT_RD)
	{
		if (param == CLIENT)
			return (info[CLIENT]);
		if (param == STATE)
			return (info[STATE]);
		if (param == SIZE)
			return (info[SIZE]);
	}
	if (flag == FT_WR)
	{
		if (param == CLIENT)
			info[CLIENT] = data;
		if (param == STATE)
			info[STATE] = data;
		if (param == SIZE)
			info[SIZE] = data;
	}
	if (flag == INIT)
		while (param < 2)
			info[param++] = 0;
	return (0);
}

////////////////////////////////////////////////////////////////////////////////
				/* very tiny so simple and little functions */
////////////////////////////////////////////////////////////////////////////////

// STR is printed, freed and given NULL value.
// Double newline is printed after the string to separate the messages.
char	*ft_print_and_free(char *str)
{
	if (str)
	{
		ft_printf("%s\n\n", str);
		free(str);
	}
	return (NULL);
}

// Processing part 2.
char	*ft_safelloc(int size)
{
	char	*str;

	str = ft_calloc(sizeof(char), size + 1);
	if (!str)
	{
		ft_printf("Internal error (calloc failed).\n");
		exit(1);
	}
	return (str);
}
