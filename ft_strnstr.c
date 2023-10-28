/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 04:57:18 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/28 18:23:28 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Looking 456, in first n=4 characters in str = A456Z 
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big != '\0' && len >= little_len)
	{
		i = 0;
		while (i < little_len && big[i] == little[i])
			i++;
		if (i == little_len)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
