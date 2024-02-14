/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:06:26 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/02/14 05:41:36 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

// Takes undefined number VAR of integers and assigns 0 to each of them.
void	ft_init(const int var, ...)
{
	va_list	args;
	int		*arg;
	int		cursor;

	cursor = 0;
	va_start(args, var);
	while (++cursor < var)
	{
		arg = va_arg(args, int *);
		*arg = 0;
	}
	va_end(args);
}
