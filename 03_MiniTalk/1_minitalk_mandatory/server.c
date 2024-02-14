/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:44:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/10 18:12:09 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	state_update(int *state)
{
	ft_printf("Updating state...\n");
	if (*state == 0)
		*state = MSG_LEN, ft_printf("Message len received.\n");
	else if (*state == MSG_LEN)
		*state = MSG, ft_printf("Message received.\n");
	else if (*state == MSG)
		*state = 0, ft_printf("Communication ended.\n");
	return (*state);
}

void	processing(const char buffer, const int state, bool *client)
{
	static int	cursor;
	static int	size;
	static char	*str;

	if (state == MSG_LEN)
		size = size * 10 + buffer - '0', ft_printf("Message len: %d\n", size);
	else if (state == MSG)
	{
		if (!str)
			str = ft_calloc(sizeof(char), size + 1);
		if (str)
		{
			str[cursor] = buffer;
			cursor++;
			if (cursor == size)
			{
				ft_printf("%s\n", str);
				free(str);
				str = NULL;
				cursor = 0;
				size = 0;
				*client = false;
			}
		}
	}
}

int	sigil(int signal)
{
	if (signal == SIGUSR1)
		return (SIGUSR2);
	return (SIGUSR1);
}

void	reception(int signal, bool *client)
{
	static int	state;
	static int	call;
	static char	buffer;

	if (signal == SIGUSR2)
		buffer |= 1 << call;
	else if (signal == SIGUSR1)
		buffer |= 0 << call;
	call++, ft_printf("Call: %d\n", call);
	if (call == 8)
	{
		ft_printf("\tReceived: %c\n", buffer);
		if (buffer == '\0' && client)
			state = state_update(&state);
		else
			processing(buffer, state, client);
		buffer = 0;
		call = 0;
	}
}

void	ft_sig(int signal)
{
	static bool	client;
	static int	call;
	static char	buffer;
	static int	pid;

	ft_printf("Signal received: %d\n", signal);
	if (!client)
	{
		if (signal == SIGUSR2)
			buffer |= 1 << call;
		if (signal == SIGUSR1)
			buffer |= 0 << call;
		call++, ft_printf("Call: %d\n", call);
		if (call == 8)
		{
			if (buffer != '\0')
				pid = pid * 10 + buffer - '0';
			else
				client = true, ft_printf("Communication with client PID: %d established.\n Receiving message lenght...\n", pid), sleep(5),  kill(pid, SIGUSR1);
			buffer = 0;
			call = 0;
		}
	}
	else
		{ft_printf("Communication in progress...\n"), reception(signal, &client);
	ft_printf("Back to sender %d\n", sigil(signal)), kill(pid, sigil(signal));
	ft_printf("Paused\n"), pause();}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		exit(1);
	ft_putendl_fd(pid, 1);
	free(pid);
	signal(SIGUSR1, ft_sig);
	signal(SIGUSR2, ft_sig);
	ft_printf("Signal handler initialized.\n");
	while (1)
		(void) 0;
}
