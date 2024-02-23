/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 05:05:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/23 02:44:14 by vsyutkin         ###   ########.fr       */
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

// [ DONE ] Fix-1: client side, add gate 4 to free *len
// [ DEPRECATED ] Fix-2: over all, review libft for string functions, no INT only ssize-t
// [ IMPOSSIBLE BC SUBJECT ] Probably implement fixed buffer, to receive unlimited len messages.
// [ DONE ] Fix-3: server side, reset str when string is not complete and client stopped sending signals.
// [ DONE ] Fix-4: makefile should not have relink for bonus. Copy same settings as for all. 
// Fix-5: EVERY PROJECT, ALL MAKEFILE: GCC ==> CC 

// Tests: 
// What if message is longer than INT_MAX? 
// 

#endif