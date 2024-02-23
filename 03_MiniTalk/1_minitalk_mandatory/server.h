/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 05:05:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/23 02:02:40 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "minitalk.h"

# define FT_RD 0
# define FT_WR 1
# define INIT 2

# define CLIENT 0
# define SIZE 1
# define STATE 2

# define FAKE -42

////////////////////////////////////////////////////////////////////////////////
				/* SERVER_UTILS */
////////////////////////////////////////////////////////////////////////////////

short int	ft_static(int data, int flag, int param);
char		timed_buffer(char data, int flag);
void		ft_print_andor_free(char **str, char buffer, int *size, int flag);
char		*ft_safelloc(int size);
int			timer(int call);

////////////////////////////////////////////////////////////////////////////////
				/* SERVER */
////////////////////////////////////////////////////////////////////////////////

void		state_update(void);
void		processing(char buffer, bool flag);
void		the_reception(int signal);
void		ft_sig(int signal, siginfo_t *info, void *context);

#endif