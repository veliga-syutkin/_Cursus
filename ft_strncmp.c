/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:25:11 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/19 13:30:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function compare s1 and s2 for n. Returns positive if value of S1 > S2, 
// negative otherwise and 0 if there is no difference. 
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	cnt;

	cnt = 0;
	if (cnt == n)
		return (0);
	while ((s1[cnt] == s2[cnt]) && (cnt < n - 1) && (s1[cnt] && s2[cnt]))
		cnt++;
	return (UNS_CHAR s1[cnt] - UNS_CHAR s2[cnt]);
}

/*
int	main(void)
{
	char s1[] = "Hello, world";
	char s2[] = "Hello";
	unsigned int n;
	int result;

	n = 6;
	result = ft_strncmp(s1, s2, n);
	printf("%d", result);
	printf("%d", strncmp(s1, s2, n));
}
*/