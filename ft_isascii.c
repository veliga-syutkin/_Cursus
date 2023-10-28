/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 05:11:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/25 09:43:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is from ascii table (man ascii)
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (TRUE);
	return (FALSE);
}
