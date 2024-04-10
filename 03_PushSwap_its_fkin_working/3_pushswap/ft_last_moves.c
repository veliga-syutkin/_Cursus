/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:08:10 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 10:16:08 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// ra ou rra
void	ft_last_last_move(t_list **list_a, t_list **list_b)
{
	int		cost_rx;
	int		cost_rrx;
	int		*data;

	cost_rx = 0;
	cost_rrx = 0;
	data = list_a_to_string(list_a, list_b);
	while (!((data[get_len(*list_a) - 1] < (*list_b)->data
				&& (*list_b)->data < data[0])
			|| (data[get_len(*list_a) - 1] > data[0]
				&& data[get_len(*list_a) - 1] > (*list_b)->data
				&& data[0] > (*list_b)->data)))
	{
		rotate_string(data, get_len(*list_a));
		cost_rx++;
	}
	free(data);
	cost_rrx = get_len(*list_a) - cost_rx;
	if (cost_rx <= cost_rrx)
		while (cost_rx--)
			ra(list_a);
	else
		while (cost_rrx--)
			rra(list_a);
}

void	ft_last_move(t_list **list_a, t_list **list_b)
{
	if ((get_last_data(*list_a, 0) < (*list_b)->data
			&& (*list_b)->data < (*list_a)->data)
		|| (get_last_data(*list_a, 0) > (*list_a)->data
			&& get_last_data(*list_a, 0) > (*list_b)->data
			&& (*list_a)->data > (*list_b)->data))
	{
		pax(list_a, list_b);
	}
	else if ((*list_b)->data > find_max(*list_a))
	{
		pax(list_a, list_b);
	}
	else
		ft_last_last_move(list_a, list_b);
}
