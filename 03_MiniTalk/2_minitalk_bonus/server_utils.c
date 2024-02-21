/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 05:27:13 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/21 08:28:57 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

////////////////////////////////////////////////////////////////////////////////
				/* STATIC VARIABLES TO USE ACROSS THE PROGRAM */
////////////////////////////////////////////////////////////////////////////////

/* STATIC VARIABLES TO USE ACROSS THE PROGRAM */
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

/* STATIC VARIABLES TO USE ACROSS THE PROGRAM */
char	timed_buffer(char data, int flag)
{
	static char	buffer;

	if (flag == FT_WR)
		buffer = data;
	return (buffer);
}

////////////////////////////////////////////////////////////////////////////////
				/* MEMORY ALLOCATION HANDLER */
////////////////////////////////////////////////////////////////////////////////

// Handle characters in a string before printing.
// If the string is full, print it and free it.
// If client aborted, free the string..
void	ft_print_andor_free(char *str, char buffer, int *size, int flag)
{
	static int		cursor;

	if (str)
	{
		str[cursor] = buffer;
		cursor++;
		if (cursor == *size)
		{
			cursor = 0;
			*size = 0;
			ft_printf("%s\n\n\n", str);
			free(str);
			ft_static(0, INIT, 0);
		}
	}
	else if (!flag)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		cursor = 0;
		*size = 0;
	}
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

////////////////////////////////////////////////////////////////////////////////
				/* THE GOOD, THE BAD AND THE UGLY CLIENT */
////////////////////////////////////////////////////////////////////////////////

// FAFO
int	timer(int call)
{
	static int	timer;

	if (call == SIGUSR1 || call == SIGUSR2)
		timer = 0;
	else
		timer++;
	if (timer >= 5)
	{
		timer = 0;
		ft_sig(FAKE, NULL, NULL);
		processing('\0', false);
		ft_static(0, FT_WR, STATE);
	}
	return (0);
}
