/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_receptive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:56:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/21 12:46:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGACTION VERSION

#include "minitalk.h"

static
char

void bad_pid(int call);

char	*stockage(char *server, char *data, int gate); 

int	send_bit_by_bit(char c, int bit)
{
	if (c & 1 << bit)
		return (SIGUSR2);
	else
		return (SIGUSR1);
}

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
		send = send_bit_by_bit(str[cursor], bit), ft_printf("Sending %c\n", str[cursor]);
		bit++, ft_printf("Call: %d\n", bit);
		if (bit == 8)
		{
			bit = 0;
			cursor++;
			if (cursor == len)
			{
				(*state)++, ft_printf("State updated: %d\n", *state);
				ft_init(2, &len, &cursor);
				// cast ft_init for those variables 
				// len = 0;
				// cursor = 0;
			}
		}
	}
	usleep(200);
	kill(server, send), ft_printf ("Signal sent: %d\n", send);
	if (*state >= 5)
		stockage(0, 0, 5);
}

char	*stockage(char *server, char *data, int gate)
{
	static char	*server_ptr;
	static char	*message_ptr;
	static char	*len;

	if (gate == 0)
	{
		server_ptr = server, ft_printf("\tServer: %s\n", server_ptr);
		message_ptr = ft_itoa(data), ft_printf("\tMessage: %s\n", message_ptr);
		len = ft_itoa(ft_strlen(message_ptr) + 1), ft_printf("\tMessage len: %s\n", len);
		/*CRASH_SHOT:*/
		// len = ft_itoa(INT_MAX+1), ft_printf("\tMessage len: %s\n", len);
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
	if (gate == 5)
	{
		free(len);
		exit(0);
	}
	return (len);
}

void	action(int signal)
{
	static int	state;
	static int	server;
	static char	*message;

	bad_pid(signal);
	ft_printf("Signal received: %d\n", signal);
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
	// ft_printf("pause\n"), pause();
}

void bad_pid(int call)
{
	static int	timer;

	if (call == SIGUSR1 || call == SIGUSR2)
		timer = 0;
	else
		timer++, ft_printf("Timer: %d\n", timer);
	if (timer >= 5)
	{
		timer = 0;
		ft_printf("Server is not responding.\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	struct 	sigaction	client;

	client.sa_handler = *action;
	client.sa_flags = 0;
	if (sigaction(SIGUSR1, &client, NULL) == -1) // here
	{
		ft_printf("Error installing signal handler"), perror("Error installing signal handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &client, NULL) == -1)
	{
		ft_printf("Error installing signal handler"), perror("Error installing signal handler");
		exit(EXIT_FAILURE);
	}
	ft_printf("Signal handler initialized.\n");
	if (argc == 1 || argc > 3)
		return (1);
	if (argc == 2)
		return (0);
	stockage(*(argv + 1), *(argv + 2), 0), ft_printf("Stockage initialized.\n");
	ft_printf("Starting communication...\n"), action(0);
	while (1)
	{
		sleep(1);
		bad_pid(0);
	}
}
