/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:35:34 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/19 19:22:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prints string *s on output fd + end of line \n 
int	ft_putendl_fd(char *s, int fd)
{
	int	state;
	int	write;

	if (!s)
		return (0);
	state = ft_putstr_fd(s, fd);
	if (state == -1)
		return (-1);
	write = ft_putchar_fd('\n', fd);
	if (write == -1)
		return (-1);
	return (state + write);
}
