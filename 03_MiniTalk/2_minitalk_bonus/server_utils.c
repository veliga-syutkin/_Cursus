/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 05:27:13 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/15 09:42:14 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

////////////////////////////////////////////////////////////////////////////////
				/* STATIC VARIABLES TO USE ACROSS THE PROGRAM */
////////////////////////////////////////////////////////////////////////////////

// Fusion of ft_static1 and ft_static2
short int	ft_static(int data, int flag, int param)
{
	if (param == CLIENT || param == BUFFER)
		return (ft_static1(data, flag, param));
	if (param == STATE || param == SIZE)
		return (ft_static2(data, flag, param));
	return (0);
}

// Stores client and buffer values.
short int	ft_static1(int data, int flag, int param)
{
	static short int	client;
	static short int	buffer;

	if (flag == FT_RD)
	{
		if (param == CLIENT)
			return (client);
		if (param == BUFFER)
			return (buffer);
	}
	if (flag == FT_WR)
	{
		if (param == CLIENT)
			client = data;
		if (param == BUFFER)
			buffer = data;
	}
	if (flag == INIT)
		client = 0;
	return (0);
}

// Stores state and size values.
short int	ft_static2(int data, int flag, int param)
{
	static short int	state;
	static short int	size;

	if (flag == FT_RD)
	{
		if (param == STATE)
			return (state);
		if (param == SIZE)
			return (size);
	}
	if (flag == FT_WR)
	{
		if (param == STATE)
			state = data;
		if (param == SIZE)
			size = data;
	}
	if (flag == INIT)
		ft_init(2, &state, &size);
	return (0);
}

////////////////////////////////////////////////////////////////////////////////
				/* very tiny so simple and little functions */
////////////////////////////////////////////////////////////////////////////////

// STR is printed, freed and given NULL value.
void	ft_print_and_free(char *str)
{
	if (str)
	{
		ft_printf("%s\n", str);
		free(str);
	}
	str = NULL;
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
