/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:10:48 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/17 03:44:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  Prints character in output fd
void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) != -1)
		return ;
}
