/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 05:30:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 13:57:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates with malloc a new string concatenating s1 + s2
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*copy;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	copy = ft_calloc(len, sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, len);
	ft_strlcat(copy, s2, len);
	return (copy);
}
