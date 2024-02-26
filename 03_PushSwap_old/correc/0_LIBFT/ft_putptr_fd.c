/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:24:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 15:31:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Converts given pointer at digit padd to hex base*/
static char	get_digit(void *ptr, int digit)
{
	unsigned long long	number;

	number = (unsigned long long)ptr;
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

/*Will initialize given integers, going from 3 line to 1 in main function*/
static void	init(int *digit, int *result, int *start_print)
{
	*digit = 15;
	*result = 2;
	*start_print = 0;
}

/*Prints on fd the adress pointed by the pointer *ptr*/
int	ft_putptr_fd(void *ptr, int fd)
{
	int	digit;
	int	result;
	int	start_print;

	if (!ptr)
		return (write(fd, "0x0", 3));
	init(&digit, &result, &start_print);
	if (ft_putchar_fd('0', fd) == -1)
		return (-1);
	if (ft_putchar_fd('x', fd) == -1)
		return (-1);
	while (digit >= 0)
	{
		if (get_digit(ptr, digit) != '0' || start_print)
		{
			if (ft_putchar_fd(get_digit(ptr, digit), fd) == -1)
				return (-1);
			start_print = 1;
			result++;
		}
		digit--;
	}
	return (result);
}
