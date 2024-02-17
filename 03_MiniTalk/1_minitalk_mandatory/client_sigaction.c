/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:56:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/15 14:28:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGACTION VERSION

#include "minitalk.h"

/*Sends the given bit of given character c*/
int	send_bit_by_bit(char c, int bit)
{
	if (c & 1 << bit)
		return (SIGUSR2);
	else
		return (SIGUSR1);
}

/* The Main Engine of the program aka demodulator
  At each response from the server, it will send the next bit of the string
composed as: 
[lenghts_of_message][\0][message][\0]*/
void	send_package(char *str, pid_t server, int *state)
{
	static int			cursor;
	static short int	bit;
	static int			len;
	static int			send;

	if (!len)
		len = ft_strlen(str) + 1;
	if (cursor <= len)
	{
		send = send_bit_by_bit(str[cursor], bit++);
		if (bit == 8)
		{
			bit = 0;
			cursor++;
			if (cursor == len)
			{
				(*state)++;
				ft_init(2, &len, &cursor);
			}
		}
	}
	usleep(200);
	kill(server, send);
	if (*state >= 5)
		exit(0);
}

/* The main tank of the program
  It stores the server pid, the message to be sent and it's lenght.
*/
char	*stockage(char *server, char *data, int gate)
{
	static char	*server_ptr;
	static char	*message_ptr;
	static char	*len;

	if (gate == 0)
	{
		server_ptr = server;
		message_ptr = data;
		len = ft_itoa(ft_strlen(message_ptr) + 1);
		if (!len || !server_ptr || !message_ptr)
		{
			ft_printf("Internal error.\n");
			exit(1);
		}
	}
	if (gate == 1)
		return (message_ptr);
	if (gate == 2)
		return (server_ptr);
	return (len);
}

/* The signal handler.
  It will be called by the system each time the server responds.
  It will send the next bit of the message.
  It will also store the server pid and the message to be sent.
*/
static void	action(int signal)
{
	static int	state;
	static int	server;
	static char	*message;

	if (signal == 0)
	{
		server = ft_atoi(stockage(0, 0, 2));
		message = stockage(0, 0, 1);
	}
	if (state == 0)
		state = MSG_LEN;
	if (state == MSG_LEN)
		send_package(stockage(0, 0, 4), server, &state);
	else if (state == MSG)
		send_package(message, server, &state);
}

/* Main function:
 - Setups signal handlers for server's response
 - Proceeds to start the communication and send the message.*/
int	main(int argc, char **argv)
{
	struct sigaction	client;

	client.sa_handler = *action;
	client.sa_flags = 0;
	if (sigaction(SIGUSR1, &client, NULL) == -1
		|| sigaction(SIGUSR2, &client, NULL) == -1)
	{
		ft_printf("Error installing signal handler");
		exit(EXIT_FAILURE);
	}
	if (argc == 1 || argc > 3)
		return (1);
	if (argc == 2)
		return (0);
	stockage(*(argv + 1), *(argv + 2), 0);
	action(0);
	while (1)
		(void) 0;
}
