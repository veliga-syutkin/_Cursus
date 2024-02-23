/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_failoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:32:21 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/23 07:39:06 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_failloc(size_t n)
{
	static int i = 0;

	if (i++ < 5)
		return malloc(n);
	return NULL;
}
# define malloc(x) ft_failloc(x)
