/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:17:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 12:44:45 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 		MAN 3 PRINTF FLAGS FOR BONUS

0 		The value should be zero padded. For d, i, u, x, X, 
		conversions, the converted value is padded on
		the left with zeros rather than blanks. If a precision is given
		with a numeric conversion (d, i, u, x, and X), the 0 flag is
		ignored (but result is same). 
		For other conversions, the behavior is undefined.

-		The converted value is to be left adjusted on the field boundary. 
		(The  default  is  right  justification.)  The converted value is 
		padded on the right	with blanks, rather than on the left with blanks or 
		zeros. A - overrides a 0 if both are given.
Example: printf("%-5d\n", num)

------

#		The value should be converted to an "alternate form". For x and X
		conversions, a nonzero result has the string "0x" (or "0X" for X
		conversions) prepended to it. 
		For other conversions, the result is undefined.

' '		(a space) A blank should be left before a positive number (or
		empty string) produced by a signed conversion.

+		A sign (+ or -) should always be placed before a number produced
		by a signed conversion. By default, a sign is used only for
		negative numbers. A + overrides a space if both are used.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Importance of each flag, in order:
1. '-' (will override '0' flag)
2. '+' (will override ' ' (space) flag)
3. ' ' (space)
4. '#'
5. '0'

*/

int	ft_flag_check(char f)
{
	if (f == '#' || f == '0' || f == ' ' || f == '+' || f == '0')
		return (true);
	return (false);
}

int	ft_flag_sharp(char flag, char c, unsigned int number, int fd)
{
	if (flag != '#')
		return (ERROR);
	if (number == 0)
		return (ft_putchar_fd('0', 1));
	if (c == 'x')
	{
		if (ft_putstr_fd("0x", 1) == ERROR)
			return (ERROR);
		return (ft_puthexl_fd(number, fd));
	}
	if (c == 'X')
	{
		if (ft_putstr_fd("0X", 1) == ERROR)
			return (ERROR);
		return (ft_puthexu_fd(number, fd));
	}
	return (ERROR);
}
