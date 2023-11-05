/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 08:03:50 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/05 12:02:36 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// calculates  the length of the string pointed to by s, 
// excluding the terminating null byte ('\0').
// Returns index of last char + 1. 
size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s && s[count] != '\0')
		count++;
	if (!s)
		return (ERROR);
	return (count);
}
