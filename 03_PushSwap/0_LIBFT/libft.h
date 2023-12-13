/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:23:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/13 16:32:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> // write
// # include <stdlib.h> // malloc, free
# include <limits.h> // INT_MAX, ... 
# include <stdbool.h>
# include <stdarg.h>

# include "ft_printf.h"

/*
WWWWWWWWW/''''''''''''''''\WWWWWWWWWW
WWWWWWWW( FUNCTION SUMMARY )WWWWWWWWW
WWWWWWWWW\,,,,,,,,,,,,,,,,/WWWWWWWWWW
*/

int			ft_atoi(const char *nptr, int *cursor_nptr);
long int	ft_atoi_long(const char *nptr, int *cursor_nptr);
size_t		ft_strlen(const char *s);

#endif