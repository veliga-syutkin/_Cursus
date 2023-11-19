/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_combined.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:20:06 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/08 01:07:55 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cursor_move(char s, int *cursor)
{
	while (*(s + cursor) && !ft_str_is_sym(*(s + cursor), "cspdiuxX%"))
	{
		cursor++;
	}
}

