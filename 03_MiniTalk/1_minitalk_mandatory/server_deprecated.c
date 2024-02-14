/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:53:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/08 19:33:53 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdbool.h>
#include <stdio.h>

bool	push(char *buffer)
{
	static int	pid;

	if (*buffer == '\0')
	{
		usleep(1000);
		kill(pid, SIGUSR2);
		ft_printf("\nConfirmation of reception from client %d...\n", pid);
		pid = 0;
		ft_printf("\t\t\tPID reset: %d\n", pid);
		return (false);
	}
	else
		pid = pid * 10 + *buffer - '0';
	return (true);
}

bool	output(char *buffer)
{
	static bool len;
	static int	cursor;
	static int	size;
	static char	*str;

	if (*buffer == '\0')
		len = true; // we have the length of the message
	if (!len)
		size = size * 10 + *buffer - '0';
	else
	{
		if (!str)
			str = ft_calloc(sizeof(char), size + 1);
		if (str)
		{
			str[cursor] = *buffer;
			cursor++;
			if (cursor == size)
			{
				ft_printf("%s\n", str);
				free(str);
				str = NULL;
				cursor = 0;
				size = 0;
				len = false;
				return (false);
			}
		}
		else
		{
			ft_printf("Internal error.\n");
			exit(1);
		}
	}
	return (true);
}

void	ft_sig(int signal)
{
	static int		call;
	static char		buffer;
	static bool		client;
	static bool		len;

	if (signal == SIGUSR2)
		buffer |= 1 << call;
	if (signal == SIGUSR1)
		buffer |= 0 << call;
	call++;
	if (call == 8)
	{
		if (!client && len)
			write(1, &buffer, 1);
		if (client)
			client = push(&buffer);
		else if (buffer == '\0' && !client)
			client = true;
		buffer = 0;
		call = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		exit(1);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	signal(SIGUSR1, ft_sig);
	signal(SIGUSR2, ft_sig);
	while (1)
		(void) 0;
}
