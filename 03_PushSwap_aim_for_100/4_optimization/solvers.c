/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:23:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/12 17:33:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	solve_50(t_list **list_a, t_list **list_b)
{
	pbx(list_a, list_b);
	while ((get_len(*list_a) > get_len(*list_b)))
	{
		weight_update_a(list_a, list_b);
		turk_move(list_a, list_b, data_min_weight(list_a));
		pbx(list_a, list_b);
	}
	while (get_len(*list_a) > 3)
		pbx(list_a, list_b);
	solve_3(list_a);
	while (*list_b)
	{
		weight_update_b(list_a, list_b);
		turk_move_b(list_a, list_b, data_min_weight(list_b));
		pax(list_a, list_b);
	}
	while ((*list_a)->data != find_min(*list_a))
		maxmin_ra_or_rra(list_a, find_min(*list_a));
}

void	solve_67(t_list **list_a, t_list **list_b)
{
	pbx(list_a, list_b);
	while (get_len(*list_a) * 2 - 1 > get_len(*list_b))
	{
		weight_update_a(list_a, list_b);
		turk_move(list_a, list_b, data_min_weight(list_a));
		pbx(list_a, list_b);
	}
	while (get_len(*list_a) > 3)
		pbx(list_a, list_b);
	solve_3(list_a);
	while (*list_b)
	{
		weight_update_b(list_a, list_b);
		turk_move_b(list_a, list_b, data_min_weight(list_b));
		pax(list_a, list_b);
	}
	while ((*list_a)->data != find_min(*list_a))
		maxmin_ra_or_rra(list_a, find_min(*list_a));
}

void	solve_75(t_list **list_a, t_list **list_b)
{
	pbx(list_a, list_b);
	while (((get_len(*list_a) * 3 - 1) > get_len(*list_b)))
	{
		weight_update_a(list_a, list_b);
		turk_move(list_a, list_b, data_min_weight(list_a));
		pbx(list_a, list_b);
	}
	while (get_len(*list_a) > 3)
		pbx(list_a, list_b);
	solve_3(list_a);
	while (*list_b)
	{
		weight_update_b(list_a, list_b);
		turk_move_b(list_a, list_b, data_min_weight(list_b));
		pax(list_a, list_b);
	}
	while ((*list_a)->data != find_min(*list_a))
		maxmin_ra_or_rra(list_a, find_min(*list_a));
}

void	solve_99(t_list **list_a, t_list **list_b)
{
	pbx(list_a, list_b);
	while ((get_len(*list_a)) > 3)
	{
		weight_update_a(list_a, list_b);
		turk_move(list_a, list_b, data_min_weight(list_a));
		pbx(list_a, list_b);
	}
	solve_3(list_a);
	while (*list_b)
	{
		weight_update_b(list_a, list_b);
		turk_move_b(list_a, list_b, data_min_weight(list_b));
		pax(list_a, list_b);
	}
	while ((*list_a)->data != find_min(*list_a))
		maxmin_ra_or_rra(list_a, find_min(*list_a));
}
