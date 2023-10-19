/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:40:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/19 07:24:37 by vsyutkin         ###   ########.fr       */
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

//Extracts new string from index start in string *s, sized of len
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

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}*/

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}*/
