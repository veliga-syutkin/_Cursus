/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:33 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 12:53:51 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int	ft_intlen(long long int n)
{
	int	result;

	result = 0;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}*/

static int	power(int n)
{
	int	result;

	result = 1;
	while (--n)
		result = result * 10;
	return (result);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	cursor;
	int	result;
	int	buffer;

	result = 0;
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	cursor = ft_intlen(n);
	while (cursor)
	{
		buffer = ft_putchar_fd((n / power(cursor--) % 10) + '0', fd);
		if (buffer == ERROR)
			return (ERROR);
		result += buffer;
	}
	return (result);
}