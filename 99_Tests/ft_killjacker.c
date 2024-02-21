/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_killjacker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:57:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/21 06:57:25 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void ft_killjacker(int pid, int signal)
{
	static int	killjacker;

	killjacker++;
	if (killjacker == 800)
		kill(pid, SIGKILL);
	else 
		kill(pid, signal);
}

# define kill(x, y) ft_killjacker(x, y)