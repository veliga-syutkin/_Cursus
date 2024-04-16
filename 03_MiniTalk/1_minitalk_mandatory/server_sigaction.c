/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:56:46 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 11:34:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

/* Keeps the track of the communication state.
*/
void	state_update(void)
{
	if (ft_static(0, FT_RD, STATE) == 0)
		ft_static(MSG_LEN, FT_WR, STATE);
	else if (ft_static(0, FT_RD, STATE) == MSG_LEN)
		ft_static(MSG, FT_WR, STATE);
	else if (ft_static(0, FT_RD, STATE) == MSG)
		ft_static(0, FT_WR, STATE);
}

/* The processing function, aka the NUCLEAR CORE of the program.
	- If the static variable is not initialized, saves the size of the message.
	- If the static variable is MSG, it saves the message and prints it.
	- If the static variable is not MSG, it updates the state.
*/
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
			ft_print_andor_free(&str, buffer, &size, flag);
	}
	if (!flag)
		ft_print_andor_free(&str, buffer, &size, flag);
	if (buffer == '\0' && flag)
		state_update();
}

/* The reception function, aka the modulator.
	- Receives the signal and updates the buffer.
	- If the buffer is full, calls the processing function.
*/
void	the_reception(int signal)
{
	static char			buffer;
	static short int	call;

	timer(signal);
	if (signal == FAKE)
	{
		buffer = 0;
		call = 0;
		ft_static(0, INIT, CLIENT);
		return ;
	}
	if (signal == SIGUSR2)
		buffer |= 1 << call;
	else if (signal == SIGUSR1)
		buffer |= 0 << call;
	call++;
	if (call == 8)
	{
		timed_buffer(buffer, FT_WR);
		processing(timed_buffer(0, FT_RD), true);
		buffer = 0;
		timed_buffer(0, FT_WR);
		call = 0;
	}
}

/* The signal handler. 
It receives the signal and the information about the sender.
	- If the static variable is not initialized, 
		it saves the sender's PID and updates the state.
	- Calls the reception function.
	- Sends the signal back to the sender.
*/
void	ft_sig(int signal, siginfo_t *info, void *context)
{
	static int	pid;

	if (signal == FAKE)
		the_reception(signal);
	else
	{
		if (!ft_static(0, FT_RD, CLIENT))
		{
			pid = info->si_pid;
			ft_static(true, FT_WR, CLIENT);
			state_update();
		}
		if (pid == info->si_pid)
		{
			the_reception(signal);
			if (!context)
				(void) 0;
			usleep(SLEEP);
			kill(pid, signal);
		}
	}
}

/* Main function:
	- Installs signal handler for SIGUSR1 and SIGUSR2. 
If it fails, the program exits.
	- Waits for signals
*/
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
		sleep(1);
		timer(0);
	}
}
