/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:53:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/23 06:18:37 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../0_LIBFT/libft.h"
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR -1

# define NO_COM 0
# define DATA_WR 0
# define DATA_MSG 1
# define DATA_PID 2
# define DATA_SIZE 3
# define MSG_LEN 3
# define MSG 4
# define DATA_END 5
# define SLEEP 200

////////////////////////////////////////////////////////////////////////////////
				/* CLIENT_UTILS */
////////////////////////////////////////////////////////////////////////////////

void	bad_pid(int call);
char	*stockage(char *server, char *data, int gate);

#endif