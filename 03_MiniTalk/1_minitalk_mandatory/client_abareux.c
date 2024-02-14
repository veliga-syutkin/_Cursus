/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_abareux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by by UwU            #+#    #+#             */
/*   Updated: 2024/02/13 08:32:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//    FOR DEBUGGING PURPOSE ONLY, DO NOT USE IN FINAL VERSION OF THE PROJECT

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#include "minitalk.h"

void	send_char(char c, pid_t pid)
{
	int	cursor;

	cursor = 0;
	while (cursor < 8)
	{
		if (c & 1 << cursor++)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		cursor;
	pid_t	pid;

	cursor = 0;
	if (argc == 1 || argc > 3)
		return (1);
	pid = ft_atoi(*(argv + 1));
	if (argc == 2)
		return (0);
	while (*(*(argv + 2) + cursor))
		send_char(*(*(argv + 2) + cursor++), pid);
	send_char(*(*(argv + 2) + cursor), pid);
}

/*void	send_char(char c, pid_t pid)
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

int	main(int argc, char **argv)
{
	int		cursor;
	pid_t	pid;

	cursor = 0;
	if (argc == 1 || argc > 3)
		return (1);
	pid = ft_atoi(*(argv + 1));
	if (argc == 2)
		return (0);
	while (*(*(argv + 2) + cursor))
		send_char(*(*(argv + 2) + cursor++), pid);
	send_char(*(*(argv + 2) + cursor), pid);
}*/