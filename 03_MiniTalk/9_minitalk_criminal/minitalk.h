/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:53:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/21 08:29:36 by vsyutkin         ###   ########.fr       */
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

////////////////////////////////////////////////////////////////////////////////
				/* CLIENT_UTILS */
////////////////////////////////////////////////////////////////////////////////

void	bad_pid(int call);
char	*stockage(char *server, char *data, int gate);

#endif