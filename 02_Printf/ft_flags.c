

#include "ft_printf.h"

/* 		MAN 3 PRINTF FLAGS FOR BONUS

0 		The value should be zero padded. For d, i, u, x, X, 
		conversions, the converted value is padded on
		the left with zeros rather than blanks. If a precision is given
		with a numeric conversion (d, i, u, x, and X), the 0 flag is
		ignored. For other conversions, the behavior is undefined.

#		The value should be converted to an "alternate form". For x and X
		conversions, a nonzero result has the string "0x" (or "0X" for X
		conversions) prepended to it. 
		For other conversions, the result is undefined.

' '		(a space) A blank should be left before a positive number (or
		empty string) produced by a signed conversion.

+		A sign (+ or -) should always be placed before a number produced
		by a signed conversion. By default, a sign is used only for
		negative numbers. A + overrides a space if both are used.
*/

int	ft_flag_check(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '+')
		return (true);
	return (false);
}

int	ft_flag_sharp(char c, unsigned int number, int fd)
{
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
	return (-1);
}
