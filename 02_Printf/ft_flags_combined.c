/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_combined.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:20:06 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/07 16:31:51 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cursor_move(char s, int *cursor)
{
	while (*(s + cursor) && !ft_str_is_sym(*(s + cursor), "cspdiuxX%"))
		cursor++;
	cursor++;
}

