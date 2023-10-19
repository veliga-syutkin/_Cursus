/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 05:06:55 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/17 05:16:57 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is printable 
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (TRUE);
	return (FALSE);
}
