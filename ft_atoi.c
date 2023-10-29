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

//			1. Skip all white spaces
static int	ft_is_white_space(char nptr)
{
	if (nptr != ' ' && nptr != '\t' && nptr != '\n'
		&& nptr != '\v' && nptr != '\f' && nptr != '\r')
	{
		return (FALSE);
	}
	return (TRUE);
}

//			2. Cheking the minus sign
static int	ft_is_negative(char c)
{
	if (c != '-')
		return (FALSE);
	return (TRUE);
}

static int	ft_is_positive(char c)
{
	if (c != '+')
		return (FALSE);
	return (TRUE);
}

/*			Converts ASCII number to integer. 
Skips all white spaces, looks if there is one minus or not, 
converts the following number in nptring, stops when encounters non digit char.  
*/
int	ft_atoi(const char *nptr)
{
	int	count;
	int	result;
	int	sign;

	if (!nptr)
		return (NULL);
	count = 0;
	result = 0;
	sign = 1;
	while (ft_is_white_space(nptr[count]) != FALSE)
		count++;
	if (ft_is_negative(nptr[count]) != FALSE)
	{
		sign = -1;
		count++;
	}
	else if (ft_is_positive(nptr[count]) != FALSE)
		count++;
	while (ft_isdigit(nptr[count]) != FALSE)
	{
		result = result * 10 + (nptr[count] - '0');
		count++;
	}
	return (result * sign);
}
