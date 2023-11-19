/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:19:45 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 02:03:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//If num lenght > pad, do nothing
//Else return pad - (num lenght).
// NUM = needed padd, lenght = occupied padd
LLONGI	ft_diff_padd(LLONGI num)
{
	LLONGI	lenght;

	lenght = ft_intlen(num);
	if (lenght <= num)
		return (0);
	return (lenght - num);
}

int	ft_flag_len(const char *s, int cursor)
{
	int	index;

	index = 0;
	while (!ft_str_is_sym(*(s + cursor + index), "cspdiuxX%"))
		index++;
	return (index);
}

// '-' flag
int	ft_putarg_minus_flag(char c, va_list args)
{
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

// Prints for n times char c on output fd
int	ft_putnchar_fd(LLONGI n, char c, int fd)
{
	char	*voide;
	LLONGI	index;
	int		result;

	voide = ft_calloc(n, sizeof(char));
	if (!voide)
		return (ERROR);
	index = 0;
	while (index < n)
	{
		voide[index] = c;
		index++;
	}
	result = ft_putstr_fd(voide, fd);
	free(voide);
	return (result);
}
