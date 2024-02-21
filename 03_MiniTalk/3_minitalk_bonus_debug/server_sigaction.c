/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:56:46 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/21 09:17:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGACTION VERSION

#include "server.h"

void	the_reception(int signal);
void	ft_sig(int signal, siginfo_t *info, void *context);

// Timer function: 
/* Make timer function containing static char buffer. 
Every ducking where where buffer is used, call the timer function
and it should return the righty thingy.*/

/* Stores buffer aka the char received (after each 8 signals).
And when there is no signals from client for X given time, the buffer wipes.*/
char timed_buffer(char data, int flag)
{
	static char	buffer;

	if (flag == FT_WR)
		buffer = data;
	return (buffer);
}

short int	ft_static(int data, int flag, int param)
{
	static char	info[3];

	if (flag == FT_RD)
	{
		if (param == CLIENT)
			return (info[CLIENT]);
		if (param == STATE)
			return (info[STATE]);
		if (param == SIZE)
			return (info[SIZE]);
	}
	if (flag == FT_WR)
	{
		if (param == CLIENT)
			info[CLIENT] = data;
		if (param == STATE)
			info[STATE] = data;
		if (param == SIZE)
			info[SIZE] = data;
	}
	if (flag == INIT)
		while (param < 2)
			info[param++] = 0;
	return (0);
}

void	state_update()
{
	ft_printf("Updating from state: %d\n", ft_static(0, FT_RD, STATE));
	if (ft_static(0, FT_RD, STATE) == 0)
		ft_static(MSG_LEN, FT_WR, STATE), ft_printf("Receiving message len...\n");
	else if (ft_static(0, FT_RD, STATE) == MSG_LEN)
		ft_static(MSG, FT_WR, STATE), ft_printf("Receiving message...\n");
	else if (ft_static(0, FT_RD, STATE) == MSG)
		ft_static(0, FT_WR, STATE), ft_printf("Communication ended, state DID update.\n");
}

// STR is printed, freed and given NULL value.
char	*ft_print_and_free(char *str)
{
	if (str)
	{
		ft_printf("%s\n", str);
		free(str);
	}
	return (NULL);
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

void	ft_print_andor_free(char *str, char buffer, int *size, int flag)
{
	static int		cursor;

	if (str)
	{
		str[cursor] = buffer;
		cursor++;
		if (cursor == *size)
		{
			cursor = 0;
			*size = 0;
			ft_printf("%s\n\n\n", str);
			free(str);
			ft_static(0, INIT, 0);
		}
	}
	else if (!flag)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		cursor = 0;
		*size = 0;
	}
}

void	processing(char buffer, bool flag)
{
	static char		*str;
	static int		size;

	if (ft_static(0, FT_RD, STATE) == MSG_LEN && buffer != '\0' && flag)
		size = size * 10 + buffer - '0';
	if (ft_static(0, FT_RD, STATE) == MSG && flag)
	{
		if (!str)
			str = ft_safelloc(size);
		if (str)
			ft_print_andor_free(str, buffer, &size, flag);
	}
	if (buffer == '\0' && flag)
		state_update();
	if (!flag)
		ft_print_andor_free(str, buffer, &size, flag);
}

int timer(int call)
{
	static int	timer;

	if (call == SIGUSR1 || call == SIGUSR2)
		timer = 0;
	else
		timer++, ft_printf("Timer: %d\n", timer);
	if (timer >= 5)
	{
		timer = 0;
		ft_sig(FAKE, NULL, NULL);
		processing('\0', false);
		ft_static(0, FT_WR, STATE);
	}
	return (0);
}

void	the_reception(int signal)
{
	static char			buffer;
	static short int	call;

	timer(signal);
	if (signal == FAKE)
	{
		call = 0;
		buffer = 0;
		ft_static(0, INIT, 0);
		ft_printf("Communication aborted: bad client.\n"); // Not included in the final code.
		return ;
	}
	if (signal == SIGUSR2)
		buffer |= 1 << call;
	else if (signal == SIGUSR1)
		buffer |= 0 << call;
	call++, ft_printf("Call: %d\n", call);
	if (call == 8)
	{
		timed_buffer(buffer, FT_WR);
		ft_printf("\tReceived & buffer: %c\n", buffer);
		processing(timed_buffer(0, FT_RD), true);
		timed_buffer(0, FT_WR);
		call = 0;
		buffer = 0;
	}
}

void	ft_sig(int signal, siginfo_t *info, void *context)
{
	static int	pid;
	// int			langis;

	if (signal == FAKE)
		the_reception(signal);
	else 
	{
		ft_printf("Signal received: %d\tclient: %d\n", signal, ft_static(0, FT_RD, CLIENT));
		if (!ft_static(0, FT_RD, CLIENT))
		{
			pid = info->si_pid, ft_printf("Signal from PID: %d\n", pid);
			ft_static(true, FT_WR, CLIENT), ft_printf("Communication with client PID: %d established.\n", pid);
			state_update();
		}
		if (pid == info->si_pid)
		{
			ft_printf("Communication in progress...\n");
			the_reception(signal);
			if (!context)
				(void) 0;
			// if (signal == SIGUSR1)
			// 	langis = SIGUSR2;
			// else
			// 	langis = SIGUSR1;
			usleep(200);
			// ft_printf("Back to sender %d\n", langis), kill(pid, langis);
			ft_printf("Back to sender %d\n", signal);
			kill(pid, signal);
		}
	}
}

int	main(void)
{
	struct sigaction	server;
	char				*pid;

	server.sa_sigaction = *ft_sig;
	server.sa_flags = SA_SIGINFO;
	pid = ft_itoa(getpid());
	if (!pid)
	{
		ft_printf("Error getting PID");
		exit(1);
	}
	ft_putendl_fd(pid, 1);
	free(pid);
	if (sigaction(SIGUSR1, &server, NULL) == -1 
		|| sigaction(SIGUSR2, &server, NULL) == -1)
	{
		ft_printf("Error installing signal handler");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		sleep(1), ft_printf("Timer ticking...\t");
		timer(0);
	};
}
