/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:10:48 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 15:32:03 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*  Prints character in output fd and return how many characters were print. 
Returns -1 if print failed.*/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
