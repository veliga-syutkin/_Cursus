/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:25:08 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/28 08:47:56 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// wrapped function
static void	ft_putstr_rec(char *str, int i, int fd)
{
	if (!str[i])
	{
		write(fd, str, i);
		return ;
	}
	ft_putstr_rec(str, i + 1, fd);
}

// Prints string *s on output fd
void	ft_putstr_fd(char *s, int fd)
{
	ft_putstr_rec(s, 0, fd);
	return ;
}
