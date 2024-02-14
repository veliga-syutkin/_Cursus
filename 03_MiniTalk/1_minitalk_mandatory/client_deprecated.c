/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:53:45 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/08 19:34:36 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	response(int signal)
{
	ft_printf("Looks like server sending something back... %d\n", signal);
	write(1, "Message delivered!\n", 18);
	exit(0);
}

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
		usleep(100);
	}
}

void	send_len(char *str, pid_t pid)
{
	char	*len;

	len = ft_itoa(ft_strlen(str));
	if (len)
	{
		while (*len)
			send_char(*len++, pid);
		send_char('\0', pid);
		free(len);
		ft_printf("\t Successfully sent message length to %d\n", pid);
	}
	else
	{
		ft_printf("Internal error.\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		cursor;
	pid_t	pid;
	char	*client;

	cursor = 0;
	if (argc == 1 || argc > 3)
		return (1);
	pid = ft_atoi(*(argv + 1));
	if (argc == 2)
		return (0);
	send_len(*(argv + 2), pid);
	while (*(*(argv + 2) + cursor))
		send_char(*(*(argv + 2) + cursor++), pid);
	send_char(*(*(argv + 2) + cursor), pid);
	ft_printf("\n\t Successfully sent message to %d\n", pid);
	client = ft_itoa(getpid());
	if (client)
	{
		cursor = 0;
		while (*(client + cursor))
			send_char(*(client + cursor++), pid);
		ft_printf("\n\t Successfully sent client's PID: %s, Waiting for confirmation from %d...\n", client, pid);
		free(client);
	}
	send_char('\0', pid);
	signal(SIGUSR2, response);
	while (1)
		(void) 0;
}
