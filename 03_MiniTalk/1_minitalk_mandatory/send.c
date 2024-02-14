/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/10 17:55:57 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static
void	send_char(char c, pid_t pid)
{
	int	cursor;

	cursor = 0;
	while (cursor < 8)
	{
		if (c & 1 << cursor++)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(SLEEP);
	}
}

int	send_pid(char *client, pid_t server)
{
	int	cursor;

	cursor = 0;
	if (!client)
	{
		ft_printf("Internal error.\n");
		exit (1);
	}
	while (client[cursor])
	{
		send_char(client[cursor], server), ft_printf("Sending %c\n", client[cursor]);
		cursor++;
	}
	send_char('\0', server);
	ft_printf("PID %s sent to server: %d\n", client, server);
	return (MSG_LEN);
}
// ^  SEND PID ONLY  ^ 
////////////////////////////////////////////////////////////////////////////////
// v SEND EVERYTHING v

static
void	send_bit_by_bit(char c, pid_t pid, int bit)
{
	if (c & 1 << bit)
		kill(pid, SIGUSR2), ft_printf("Sending signal %d\n", SIGUSR2);
	else
		kill(pid, SIGUSR1), ft_printf("Sending signal %d\n", SIGUSR1);
}

void	send_package(char *str, pid_t server, int *state)
{
	static int	cursor;
	static int	bit;
	static int	len;

	if (!len)
		len = ft_strlen(str) + 1;
	if (cursor <= len)
	{
		send_bit_by_bit(str[cursor], server, bit), ft_printf("Sending %c\n", str[cursor]);
		bit++;
		if (bit == 8)
		{
			bit = 0;
			cursor++;
			if (cursor == len)
			{
				(*state)++;
				if (*state >= 5)
					exit(0);
			}
		}
	}
}
