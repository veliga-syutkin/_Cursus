/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:53:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/10 15:56:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../0_LIBFT/libft.h"
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>

# define NO_COM 0
# define ESTABLISH 1
# define PID_RECEPETION 2
# define MSG_LEN 3
# define MSG 4
# define SLEEP 100000 //<- change before submit

void	send_package(char *str, pid_t server, int *state);
int		send_pid(char *client, pid_t server);

#endif