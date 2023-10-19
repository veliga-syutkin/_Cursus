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
/*						- MAIN HERE -
#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <string_to_convert>\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];
    int result_ft_atoi = ft_atoi(input);
    int result_atoi = atoi(input);

    printf("Input string: %s\n", input);
    printf("Converted integer using ft_atoi: %d\n", result_ft_atoi);
    printf("Converted integer using atoi: %d\n", result_atoi);

    if (result_ft_atoi == result_atoi)
    {
        printf("Results match!\n");
    }
    else
    {
        printf("Results differ!\n");
    }

    return 0;
}
*/