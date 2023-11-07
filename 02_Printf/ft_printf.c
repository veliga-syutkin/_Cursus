/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:12:47 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 14:41:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Standart way: no flag, only conversion
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

/*
static int	ft_putarg_flag(char flag, char c, va_list args)
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
	if (c == 'x' || c == 'X')
		return (ft_flag_sharp(flag, c, va_arg(args, unsigned int), 1));
	return (ft_putchar_fd('%', 1));
}

static int	ft_putarg_chek(char flag, char c, va_list args)
{
	if (ft_flag_check(flag))
		return (ft_putarg_flag(flag, c, args));
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
*/

// checks if after '%' is a flag or conversion
// returns 0 (false) if there is none
static bool	ft_percent_check(char c)
{
	int		i;
	char	charset[15];

	*charset = "cspdiuxX%0 #-+";
	charset[15] = '\0';
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (true);
		i++;
	}
	return (false);
}

// If there is only conversion, go standart way. 
// If there is any flag, pre-process it before going standart way.
static int	ft_dependance(const char *s, int cursor, va_list args)
{
	int	result;
	int	temp;

	temp = 0;
	if (*(s + cursor) == '%' && ft_str_is_sym(*(s + cursor + 1), "cspdiuxX%"))
		return (ft_putarg(*(s + cursor + 1), args));
	if (*(s + cursor) == '%' && *(s + cursor + 1) == '-')
	{
		result = ft_putarg_minus_flag(*(s + cursor + ft_atoi(*(s + cursor))), args);
		if (result == ERROR)
			return (ERROR);
		temp = ft_diff_padd(s, cursor, ft_atoi(*(s + cursor)));
		while (temp > 0)
			result += ft_putchar_fd(' ', 1);
	}
	return (ft_putarg_chek(*(s + cursor), *(s + cursor + 1), args));
}

int	ft_printf(const char *s, ...)
{
	int		cursor;
	va_list	args;
	int		result;
	int		buffer;

	cursor = 0; //ft_init
	result = 0;
	va_start(args, s);
	while (*(s + cursor))
	{
		if (*(s + cursor) == '%'
			&& ft_str_is_sym(*(s + cursor + 1), "cspdiuxX%0 #-+"))
		{
			buffer = ft_dependance(s, cursor, args);
			ft_cursor_move(s, &cursor);
		}
		else if (*(s + cursor) == '%')
			buffer = ft_putchar_fd(*(s + cursor++), 1);
		else
			buffer = ft_putchar_fd(*(s + cursor), 1);
		if (buffer == ERROR)
			return (ERROR);
		result = result + buffer;
		cursor++;
	}
	va_end(args);
	return (result);
}
/*
int	ft_printf(const char *s, ...)
{
	int		cursor;
	va_list	args;
	int		result;
	int		buffer;

	cursor = 0; //ft_init
	result = 0;
	va_start(args, s);
	while (*(s + cursor))
	{
		if (*(s + cursor) == '%' && *(s + cursor + 1) != '%')
		{
			cursor++;
			buffer = ft_putarg_chek(*(s + cursor), *(s + cursor + 1), args);
		}
		else if (*(s + cursor) == '%')
			buffer = ft_putchar_fd(*(s + cursor++), 1);
		else
			buffer = ft_putchar_fd(*(s + cursor), 1);
		if (buffer == ERROR)
			return (ERROR);
		result = result + buffer;
		cursor++;
	}
	va_end(args);
	return (result);
}
*/