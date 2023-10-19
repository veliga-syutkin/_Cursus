/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 01:39:51 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/18 02:08:58 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is digit (or number from 0 to 9) 
// or alphebetic, either upper- or lower-case.
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != FALSE || ft_isdigit(c) != FALSE)
		return (TRUE);
	return (FALSE);
}
