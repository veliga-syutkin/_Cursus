/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 15:33:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Converts given number n to it's absolute value*/
static long long int	ft_abs(long long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/* Gets padd lenghts of given number n*/
static int	ft_intlen(long long int n)
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

/* Gets power of given number in calculated format from (10^X)*/
static long long int	power(int n)
{
	long long int	result;

	result = 1;
	while (--n)
		result = result * 10;
	return (result);
}

/* Prints on fd a number given in n.
Function will print given n from left to right, 
as a human with cursor will do.
*/
int	ft_putnbr_fd(long long int n, int fd)
{
	int	cursor;
	int	result;

	result = 0;
	if (n == 0)
		result += ft_putchar_fd(48, fd);
	if (n == 0)
		return (result);
	if (n < 0)
	{
		if (ft_putchar_fd(45, fd) == -1)
			return (-1);
	}
	else
		result--;
	result++;
	cursor = ft_intlen(n);
	while (cursor)
	{
		if (ft_putchar_fd(ft_abs(n / power(cursor--) % 10) + 48, fd) == -1)
			return (-1);
		result++;
	}
	return (result);
}
