/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:19:45 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 14:30:41 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//If num lenght > pad, do nothing
//Else return pad - (num lenght).
int	ft_diff_padd(const char *s, int cursor, LLONGI num)
{
	LLONGI	lenght;
	LLONGI	pad;

	pad = ft_atoi(*(s + cursor));
	lenght = ft_intlen(num);
	if (pad <= num)
		return (0);
	return (pad - num);
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
