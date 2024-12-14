/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:46:15 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 03:19:25 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// Print Error on fd 2 and exit with status 1 aka there was an error encountered
// while running the program. (if the program is runned successfully, exit(0))
void	error(t_list **list, int fd)
{
	ft_putstr_fd("Error\n", fd);
	clear_list(list);
	exit(1);
}
