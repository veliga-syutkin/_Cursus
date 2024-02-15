/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:56:46 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/15 09:21:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SIGACTION VERSION

#include "server.h"

// struct SIGACTION
// {
// 	void	(*sa_handler)(int);
// 	void	(*sa_sigaction)(int, siginfo_t *, void *);
// 	sigset_t	sa_mask;
// 	int		sa_flags;
// };

// Takes undefined number of integers and assigns 0 to each of them.
void	ft_init(const int var, ...)
{
	va_list	args;
	int		*arg;
	int		cursor;

	cursor = 0;
	va_start(args, var);
	while (++cursor < var)
	{
		arg = va_arg(args, int *);
		*arg = 0;
	}
	va_end(args);
}

short int	ft_static(int data, int flag, int param)
{
	static short int	client;
	static short int	buffer;
	static short int	state;
	static short int	size;

	if (flag == FT_RD)
	{
		if (param == CLIENT)
			return (client);
		if (param == BUFFER)
			return (buffer);
		if (param == STATE)
			return (state);
		if (param == SIZE)
			return (size);
	}
	if (flag == FT_WR)
	{
		if (param == CLIENT)
			client = data;
		if (param == BUFFER)
			buffer = data;
		if (param == STATE)
			state = data;
		if (param == SIZE)
			size = data;
	}
	if (flag == INIT)
	{
		client = false;
		buffer = 0;
		size = 0;
	}
	return (0);
}

// // Fusion of ft_static1 and ft_static2
// short int	ft_static1(int data, int flag, int param);
// short int	ft_static2(int data, int flag, int param);
// short int	ft_static(int data, int flag, int param)
// {
// 	if (param == CLIENT || param == BUFFER)
// 		return (ft_static1(data, flag, param));
// 	if (param == STATE || param == SIZE)
// 		return (ft_static2(data, flag, param));
// 	return (0);
// }

// // Stores client and buffer values.
// short int	ft_static1(int data, int flag, int param)
// {
// 	static short int	client;
// 	static short int	buffer;

// 	if (flag == FT_RD)
// 	{
// 		if (param == CLIENT)
// 			return (client);
// 		if (param == BUFFER)
// 			return (buffer);
// 	}
// 	if (flag == FT_WR)
// 	{
// 		if (param == CLIENT)
// 			client = data;
// 		if (param == BUFFER)
// 			buffer = data;
// 	}
// 	if (flag == INIT)
// 		client = 0;
// 	return (0);
// }

// // Stores state and size values.
// short int	ft_static2(int data, int flag, int param)
// {
// 	static short int	state;
// 	static short int	size;

// 	if (flag == FT_RD)
// 	{
// 		if (param == STATE)
// 			return (state);
// 		if (param == SIZE)
// 			return (size);
// 	}
// 	if (flag == FT_WR)
// 	{
// 		if (param == STATE)
// 			state = data;
// 		if (param == SIZE)
// 			size = data;
// 	}
// 	if (flag == INIT)
// 	{
// 		state = 0;
// 		size = 0;
// 	}
// 	return (0);
// }

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
void	ft_print_and_free(char *str)
{
	if (str)
	{
		ft_printf("%s\n", str);
		free(str);
	}
	str = NULL;
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

void	processing(char buffer)
{
	static int		size;
	static char		*str;
	static int		cursor;

	if (ft_static(0, FT_RD, STATE) == MSG_LEN && ft_static(0, FT_RD, BUFFER) != '\0')
		size = size * 10 + ft_static(0, FT_RD, BUFFER) - '0', ft_printf("\t\t\t\tMessage len: %d\n\n", size);
	if (ft_static(0, FT_RD, STATE) == MSG)
	{
		if (!str)
			str = ft_safelloc(size);
		if (str)
		{
			str[cursor] = buffer, ft_printf("\tCursor: %d \t MSG: %s \tBuffer: %c\n", cursor, str, buffer);
			cursor++;
			if (cursor == size)
			{
				cursor = 0;
				size = 0;
				ft_print_and_free(str), ft_printf("\t <-- HERE'S THE MESSAGE\n");
				ft_printf("Memory freed.\n");
				ft_static(0, INIT, 0), ft_printf("State updatedn't: %d\n", ft_static(0, FT_RD, STATE));
			}
		}
	}
	if (ft_static(0, FT_RD, BUFFER) == '\0')
		state_update();
}

void	the_reception(int signal)
{
	static char			buffer;
	static short int	call;

	if (signal == SIGUSR2)
		buffer |= 1 << call;
	else if (signal == SIGUSR1)
		buffer |= 0 << call;
	call++, ft_printf("Call: %d\n", call);
	if (call == 8)
	{
		ft_printf("\tReceived: %c\n", buffer);
		ft_static(buffer, FT_WR, BUFFER);
		ft_printf("\tBuffer: %c\n", ft_static(0, FT_RD, BUFFER));
		processing(buffer);
		buffer = 0;
		call = 0;
	}
}

void	ft_sig(int signal, siginfo_t *info, void *context)
{
	static int	pid;
	int			langis;

	ft_printf("Signal received: %d\tclient: %d\n", signal, ft_static(0, FT_RD, CLIENT));
	if (!ft_static(0, FT_RD, CLIENT))
	{
		pid = info->si_pid, ft_printf("Signal from PID: %d\n", pid);
		ft_static(true, FT_WR, CLIENT), ft_printf("Communication with client PID: %d established.\n", pid);
		state_update();
	}
	ft_printf("Communication in progress...\n"), the_reception(signal);
	if (!context)
		(void) 0;
	if (signal == SIGUSR1)
		langis = SIGUSR2;
	else
		langis = SIGUSR1;
	usleep(200);
	ft_printf("Back to sender %d\n", langis), kill(pid, langis);
}

int	main(void)
{
	struct sigaction	server;
	char				*pid;

	server.sa_sigaction = *ft_sig;
	server.sa_flags = SA_SIGINFO;
	pid = ft_itoa(getpid());
	if (!pid)
		exit(1);
	ft_putendl_fd(pid, 1);
	free(pid);
	if (sigaction(SIGUSR1, &server, NULL) == -1 
		|| sigaction(SIGUSR2, &server, NULL) == -1)
	{
		ft_printf("Error installing signal handler");
		exit(EXIT_FAILURE);
	}
	while (1)
		(void) 0;
}
