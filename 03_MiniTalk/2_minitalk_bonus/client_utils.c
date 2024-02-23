/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:30:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/23 06:19:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Looks if the server is responding. 
If not, shut downs the client.*/
void	bad_pid(int call)
{
	static int	timer;

	if (call == SIGUSR1 || call == SIGUSR2)
		timer = 0;
	else
		timer++;
	if (timer >= 5)
	{
		timer = 0;
		ft_printf("Server is not responding.\n");
		exit(EXIT_FAILURE);
	}
}
