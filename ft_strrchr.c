/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:23:24 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 14:40:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a pointer to the last occurrence of the character c in the string s.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			result = ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (result);
}
