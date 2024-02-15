/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 05:05:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/15 09:04:18 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "minitalk.h"

# define FT_RD 0
# define FT_WR 1
# define INIT 2

# define PID 0
# define CLIENT 1
# define CALL 2
# define BUFFER 3
# define STATE 4
# define SIZE 5
# define STR 6
# define CURSOR 7

////////////////////////////////////////////////////////////////////////////////
				/* SERVER_UTILS */
////////////////////////////////////////////////////////////////////////////////

short int	ft_static(int data, int flag, int param);
short int	ft_static1(int data, int flag, int param);
short int	ft_static2(int data, int flag, int param);
void		ft_print_and_free(char *str);
char		*ft_safelloc(int size);

////////////////////////////////////////////////////////////////////////////////
				/* SERVER */
////////////////////////////////////////////////////////////////////////////////

void	state_update();
void	processing(char buffer);
void	the_reception(int signal);
void	ft_sig(int signal, siginfo_t *info, void *context);
void	ft_perror(char *str);

#endif