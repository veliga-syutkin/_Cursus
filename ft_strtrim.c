/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:07:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 14:40:54 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// checks if char c is in string charset
static int	ft_str_is_sym(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

// returns new string from s1 after cutting at start and end any chars in set. 
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) + 1;
	while (ft_str_is_sym(s1[start], set))
		start++;
	while (ft_str_is_sym(s1[end - 2], set))
		end--;
	len = end - start - 1;
	return (ft_substr(s1, start, len));
}
