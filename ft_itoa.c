/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:28:22 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/28 18:19:55 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// gets the lenght of n, returns it + 1 (for \0)
static int	ft_intindex(int n)
{
	int		index;

	index = 2;
	if (n < 0)
	{
		n = -n;
		index++;
	}
	while (n > 9)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

// Converts an integer n and returns a pointer to a new string
char	*ft_itoa(int n)
{
	char	*arr;
	int		index;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	index = ft_intindex(n);
	arr = ft_calloc(index, sizeof(char));
	if (arr == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		arr[0] = '-';
	}
	index--;
	while (index > 0)
	{
		index--;
		if (arr[index] != '-')
		{
			arr[index] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (arr);
}
