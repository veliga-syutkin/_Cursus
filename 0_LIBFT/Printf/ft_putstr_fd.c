/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:25:08 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/05 12:02:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// wrapped function
static int	ft_putstr_rec(char *str, int i, int fd)
{
	if (!str[i])
		return (write(fd, str, i));
	ft_putstr_rec(str, i + 1, fd);
	return (0);
}

// Prints string *s on output fd
int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ERROR);
	return (ft_putstr_rec(s, 0, fd));
}
