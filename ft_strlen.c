/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:03:50 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/19 08:38:06 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// calculates  the length of the string pointed to by s, 
// excluding the terminating null byte ('\0').
// Returns index of last char + 1. 
size_t	ft_strlen(const char *s);

/*size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}*/

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

/*
int	main(void)
{
	char str[0];
	printf("%d", ft_strlen(str));
	return (0);
}
*/