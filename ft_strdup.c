/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 07:29:16 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 14:39:05 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a pointer to a new string which is a duplicate of the string s,
 and terminated with \0. Memory for the new string is obtained with malloc(3).
*/
char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	int		len;
	char	*copy;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	copy = (char *)malloc(len * (sizeof(char)));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len);
	return (copy);
}
