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
/*

	Protection includes: 
	against INT_MAX overflow (as said in the man malloc and man calloc),
vulnerability explanation here: 
https://msrc.microsoft.com/blog/2021/04/
badalloc-memory-allocation-vulnerabilities-could-affect-wide-range-of-iot-and
-ot-devices-in-industrial-medical-and-enterprise-networks/
*/
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
/*	o7 MAN CALLOC o7 
from Linux Ubuntu 22.04 LTS
	The calloc() function allocates memory for an array 
of nmemb elements of size bytes each 
and returns a pointer to the allocated memory.  
	The memory is set to zero.  
	If nmemb or size is  0,  then  calloc()  returns  either NULL,  
or  a  unique  pointer value that can later be successfully passed to free().  
	If the multiplication of nmemb and size would result in integer overflow, 
then calloc() returns an  error. 
By contrast, an integer overflow would not be detected 
in the following call to malloc(), 
with the result that an incorrectly sized block of memory would be allocated:
           malloc(nmemb * size);

*/
/*
#include <stdio.h>
int main ()
{
	size_t memb = INT_MAX;
	size_t size = 100;

//	printf("\nFT_Calloc: %p\n", ft_calloc(memb, size));
	printf("\n_calloc_long_max %p", calloc(memb, size));
	printf("\n calloc INT MAX x 20: %p", calloc(INT_MAX, 20));
}
*/