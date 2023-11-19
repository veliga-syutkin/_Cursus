/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:24:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/05 12:01:45 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// pass a number, get it's hex value at digit place
static char	get_digit(unsigned int number, int digit)
{
	while (digit)
	{
		number = number / 16;
		digit--;
	}
	number = number % 16;
	if (number <= 9)
		return (number + '0');
	else
		return (number - 10 + 'a');
}

// Print the pointer in hex lower case
int	ft_puthexl_fd(unsigned int number, int fd)
{
	int		digit;
	char	buffer;
	_Bool	start_print;
	int		result;

	digit = 8;
	start_print = 0;
	result = 0;
	while (digit >= 0)
	{
		buffer = get_digit(number, digit--);
		if (buffer != '0' || start_print || digit < 0)
		{
			if (ft_putchar_fd(buffer, fd) == ERROR)
				return (ERROR);
			start_print = 1;
			result++;
		}	
	}
	return (result);
}
