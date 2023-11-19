/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:39:24 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 12:51:25 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_abs(long long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_intlen(long long int n)
{
	int	result;

	result = 0;
	n = ft_abs(n);
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static long long int	power(int n)
{
	long long int	result;

	result = 1;
	while (--n)
		result = result * 10;
	return (result);
}

// Prints L.L. integer n in output fd
int	ft_putnbr_fd(long long int n, int fd)
{
	int	cursor;
	int	result;

	result = 0;
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == ERROR)
			return (ERROR);
	}
	else
		result--;
	result++;
	cursor = ft_intlen(n);
	while (cursor)
	{
		if (ft_putchar_fd(ft_abs(n / power(cursor--) % 10) + '0', fd) == ERROR)
			return (ERROR);
		result++;
	}
	return (result);
}
