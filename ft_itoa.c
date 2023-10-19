/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:28:22 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/19 09:54:18 by vsyutkin         ###   ########.fr       */
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

	if (n == -2147483648)
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
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];

    // Test ft_itoa
    int number = ft_atoi(input);  // Convertir la chaîne en entier
    char *ft_itoa_result = ft_itoa(number);  // Utiliser ft_itoa
    printf("ft_itoa Result: %s\n", ft_itoa_result);
    free(ft_itoa_result);

    // Test atoi
    int atoi_result = atoi(input);  // Utiliser la fonction système atoi
    printf("atoi Result: %d\n", atoi_result);

    return 0;
}
*/