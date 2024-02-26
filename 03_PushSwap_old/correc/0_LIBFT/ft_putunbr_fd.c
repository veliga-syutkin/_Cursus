/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:33 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 15:30:32 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Gets padd lenghts of given number n*/
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
}

/* Gets power of given number in calculated format from (10^X)*/
static int	power(int n)
{
	int	result;

	result = 1;
	while (--n)
		result = result * 10;
	return (result);
}

/* Prints on fd a unsigned number given in n.
Function will print given n from left to right, 
as a human with cursor will do.
*/
int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	cursor;
	int	result;
	int	buffer;

	result = 0;
	if (n == 0)
		result += ft_putchar_fd(48, fd);
	if (n == 0)
		return (result);
	cursor = ft_intlen(n);
	while (cursor)
	{
		buffer = ft_putchar_fd((n / power(cursor--) % 10) + 48, fd);
		if (buffer == -1)
			return (-1);
		result += buffer;
	}
	return (result);
}
