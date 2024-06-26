/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:36:46 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 15:36:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Is given a conversion C and the argument in va_list. 
*/
static int	ft_putarg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	if (c == 'x')
		return (ft_puthexl_fd(va_arg(args, unsigned int), 1));
	if (c == 'X')
		return (ft_puthexu_fd(va_arg(args, unsigned int), 1));
	return (ft_putchar_fd('%', 1));
}

/* Printf (3) worst replica in the world. 
Converts only cspdiuxX%, without any flag.
Will parse given string to detect an '%' and get the conversion instruction,
summoning function above to print in to the terminal (fd = 1).
*/
int	ft_printf(const char *s, ...)
{
	int		cursor;
	va_list	args;
	int		result;
	int		buffer;

	cursor = 0;
	va_start(args, s);
	result = 0;
	while (*(s + cursor))
	{
		if (*(s + cursor) == '%' && *(s + cursor + 1) != '%')
			buffer = ft_putarg(*(s + cursor++ + 1), args);
		else if (*(s + cursor) == '%')
			buffer = ft_putchar_fd(*(s + cursor++), 1);
		else
			buffer = ft_putchar_fd(*(s + cursor), 1);
		if (buffer == -1)
			return (-1);
		result += buffer;
		cursor++;
	}
	va_end(args);
	return (result);
}
