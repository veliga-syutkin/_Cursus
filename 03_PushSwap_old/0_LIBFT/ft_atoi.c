/* ************************************************************************** */
/*																		    */
/*														:::      ::::::::   */
/*   ft_atoi.c										  :+:      :+:    :+:   */
/*												    +:+ +:+		 +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>		  +#+  +:+       +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/17 00:45:02 by vsyutkin		  #+#    #+#		     */
/*   Updated: 2023/10/17 01:58:30 by vsyutkin		 ###   ########.fr       */
/*																		    */
/* ************************************************************************** */

#include "libft.h"

static
void	ft_getsign(const char *c, int *sign, int *cursor, int *cursor_nptr)
{
	if (*c == '+')
		*sign = 1;
	else if (*c == '-')
		*sign = -1;
	else
		*sign = 0;
	*cursor = *cursor + 1;
	*cursor_nptr = *cursor_nptr + 1;
	return ;
}

int	ft_atoi(const char *nptr, int *cursor_nptr)
{
	int	cursor;
	int	sign;
	int	result;

	cursor = 0;
	result = 0;
	if (!ft_isdigit(*(nptr + cursor)))
		ft_getsign(nptr + cursor, &sign, &cursor, cursor_nptr);
	else if (ft_isdigit(*(nptr + cursor)))
		sign = 1;
	while (*(nptr + cursor) == '0')
	{
		cursor++;
		*cursor_nptr = *cursor_nptr + 1;
	}
	while (ft_isdigit(*(nptr + cursor)))
	{
		result = (result * 10) + *((char *)nptr + cursor++) - '0';
		*cursor_nptr = *cursor_nptr + 1;
	}
	if (!cursor)
		*cursor_nptr = *cursor_nptr + 1;
	return (result * sign);
}

long int	ft_atoi_long(const char *nptr, int *cursor_nptr)
{
	int			cursor;
	int			sign;
	long int	result;

	cursor = 0;
	result = 0;
	if (!ft_isdigit(*(nptr + cursor)))
		ft_getsign(nptr + cursor, &sign, &cursor, cursor_nptr);
	else if (ft_isdigit(*(nptr + cursor)))
		sign = 1;
	while (*(nptr + cursor) == '0')
		cursor++;
	while (ft_isdigit(*(nptr + cursor)))
		result = (result * 10) + *((char *)nptr + cursor++) - '0';
	return (result * sign);
}
