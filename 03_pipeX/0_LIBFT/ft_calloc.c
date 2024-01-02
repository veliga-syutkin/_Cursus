/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:44:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/17 09:44:49 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Malloc but all is \0
// If nmemb or size is 0, returns NULL. 
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

/*
	Protection includes: 
	against INT_MAX overflow (as said in the man malloc and man calloc),
vulnerability explanation here: 
https://msrc.microsoft.com/blog/2021/04/
badalloc-memory-allocation-vulnerabilities-could-affect-wide-range-of-iot-and
-ot-devices-in-industrial-medical-and-enterprise-networks/
*/