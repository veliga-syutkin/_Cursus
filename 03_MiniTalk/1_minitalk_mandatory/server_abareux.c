/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by by UwU            #+#    #+#             */
/*   Updated: 2024/01/07 20:55:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//    FOR DEBUGGING PURPOSE ONLY, DO NOT USE IN FINAL VERSION OF THE PROJECT

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "minitalk.h"

#include <stdio.h>

void	ft_sig(int signal)
{
	static int	call;
	static char	buffer;

	if (signal == SIGUSR2)
		buffer |= 1 << call;
	if (signal == SIGUSR1)
		buffer |= 0 << call;
	call++;
	if (call == 8)
	{
		write(1, &buffer, 1);
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

// #include <stdio.h>

// void	ft_sig(int signal)
// {
// 	static int	call;
// 	static char	buffer;

// 	if (signal == SIGUSR2)
// 		buffer |= 1 << call;
// 	if (signal == SIGUSR1)
// 		buffer |= 0 << call;
// 	call++;
// 	if (call == 8)
// 	{
// 		write(1, &buffer, 1);
// 		buffer = 0;
// 		call = 0;
// 	}
// }

// int	main(void)
// {
// 	char	*pid;

// 	pid = ft_itoa(getpid());
// 	if (!pid)
// 		exit(1);
// 	write(1, pid, ft_strlen(pid));
// 	write(1, "\n", 1);
// 	free(pid);
// 	signal(SIGUSR1, ft_sig);
// 	signal(SIGUSR2, ft_sig);
// 	while (1)
// 		(void) 0;
// }