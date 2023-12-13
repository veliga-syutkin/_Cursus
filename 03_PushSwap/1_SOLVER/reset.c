/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:17 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/13 15:23:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_rb(t_list  **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rx(list_b);
		ft_putstr_fd("rb\n", 1);
	}
}

void	reset_rrb(t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rrx(list_b);
		ft_putstr_fd("rr\n", 1);
	}
}
