/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:46:15 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/18 02:13:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print Error on fd 2 and exit with status 1 aka there was an error encountered
// while running the program. (if the program is runned successfully, exit(0))
void	error(t_list **list)
{
	ft_putstr_fd("Error\n", 2);
	clear_list(list);
	exit(1);
}
