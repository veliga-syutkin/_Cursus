/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:40:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/28 06:41:38 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* It creates a new string by copying the first n characters of str 
and adds a null character at the end. 
It returns a pointer to the new string. */
static char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;

	copy = (char *)malloc(n * (sizeof(char)));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, n);
	return (copy);
}

//Extracts new string from index start in string *s, sized of len.
//No frees. 
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	else if (start >= ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	return (ft_strndup(&s[start], len + 1));
}
