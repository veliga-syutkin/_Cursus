/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:44:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/10 17:18:13 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static
char	*stockage(char *client, char *server, char *data, int gate)
{
	static char	*server_ptr;
	static char	*message_ptr;
	static char	*client_ptr;
	static char	*len;

	if (gate == 0)
	{
		server_ptr = ft_strdup(server);
		client_ptr = ft_strdup(client);
		free(client), ft_printf("Freeing PID.\n");
		message_ptr = ft_strdup(data);
		len = ft_itoa(ft_strlen(message_ptr)), ft_printf("Message len: %s\n", len);
		if (!len || !server_ptr || !message_ptr || !client_ptr)
		{
			ft_printf("Internal error.\n");
			exit(1);
		}
	}
	if (gate == 1)
		return (message_ptr);
	if (gate == 2)
		return (server_ptr);
	if (gate == 3)
		return (client_ptr);
	return (len);
}

static
void	processing(int signal)
{
	static int	state;
	static int	server;
	static char	*message;
	static char	*client;

	ft_printf("Signal received: %d\n", signal);
	if (signal == 0)
	{
		server = ft_atoi(stockage(0, 0, 0, 2));
		message = stockage(0, 0, 0, 1);
		client = stockage(0, 0, 0, 3);
	}
	if (state == 0)
		ft_printf("sending pid...\n"), state = send_pid(client, server);
	else if (state == MSG_LEN)
		send_package(stockage(0, 0, 0, 4), server, &state);
	else if (state == MSG)
		send_package(message, server, &state);
	ft_printf("pause\n"), pause();
}

int	main(int argc, char **argv)
{
	char	*pid;

	signal(SIGUSR1, processing);
	signal(SIGUSR2, processing);
	ft_printf("Signal handler initialized.\n");
	if (argc == 1 || argc > 3)
		return (1);
	if (argc == 2)
		return (0);
	pid = ft_itoa(getpid());
	if (!pid)
	{
		ft_printf("Internal error.\n");
		exit(1);
	}
	ft_printf("Client PID: %s\n", pid);
	stockage(pid, *(argv + 1), *(argv + 2), 0), ft_printf("Stockage initialized.\n");
	ft_printf("Starting communication...\n"), processing(0);
	free(pid), ft_printf("Freeing PID.\n");
	while (1)
		(void) 0;
}
