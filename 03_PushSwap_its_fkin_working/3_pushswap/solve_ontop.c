/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ontop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:33:59 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 15:28:51 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// [ DEPRECATED ]
void	solve_ontop(t_list **list)
{
	static short int	ontop;

	if (ontop == 4)
		ontop = 0;
	if (ontop == 0)
	{
		if ((*list)->data > (*list)->next->data)
			sa(list);
		ontop++;
	}
}
