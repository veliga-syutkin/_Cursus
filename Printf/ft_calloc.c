/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:49:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Malloc but all is \0
// If nmemb or size is 0, returns NULL. 

// Fills area of memory from *s with char c for n bytes. (bzero with extra step)
static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!s)
		return (NULL);
	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

// Erases data with \0 in n bytes starting from *s
static void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ar;

	if (nmemb > INT_MAX || size > INT_MAX || nmemb * size > INT_MAX)
		return (NULL);
	ar = (void *)malloc(nmemb * size);
	if (ar == NULL)
		return (NULL);
	ft_bzero(ar, nmemb * size);
	return (ar);
}
