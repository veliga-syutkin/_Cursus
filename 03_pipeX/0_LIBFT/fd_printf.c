/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:57:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/02 12:48:59 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_printf.h"

/* Is given fd, a conversion C and the argument in va_list. 
*/
static int	ft_putarg(int fd, char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (c == 'p')
		return (ft_putptr_fd(va_arg(args, void *), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (c == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), fd));
	if (c == 'x')
		return (ft_puthexl_fd(va_arg(args, unsigned int), fd));
	if (c == 'X')
		return (ft_puthexu_fd(va_arg(args, unsigned int), fd));
	return (ft_putchar_fd('%', fd));
}

/* Printf (3) worst mutant in the world. 
Converts only cspdiuxX%, without any flag.
Will parse given string to detect an '%' and get the conversion instruction,
summoning function above to print in to the terminal (fd = 1).
*/
int	fd_printf(int fd, const char *s, ...)
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
			buffer = ft_putarg(fd, *(s + cursor++ + 1), args);
		else if (*(s + cursor) == '%')
			buffer = ft_putchar_fd(*(s + cursor++), fd);
		else
			buffer = ft_putchar_fd(*(s + cursor), fd);
		if (buffer == -1)
			return (-1);
		result += buffer;
		cursor++;
	}
	va_end(args);
	return (result);
}
