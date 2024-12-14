/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:23:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/13 17:09:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	solve_50(t_list **list_a, t_list **list_b)
{
	flag_method(WRITE, METHOD_50);
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

void	solve_66(t_list **list_a, t_list **list_b)
{
	flag_method(WRITE, METHOD_66);
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
	flag_method(WRITE, METHOD_75);
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
	flag_method(WRITE, METHOD_99);
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

void	run_solvers(t_list **list_a, t_list **list_b, int argc, char **argv)
{
	solve_50(list_a, list_b);
	clear_list(list_a);
	(*list_a) = setup(argc, argv);
	(*list_b) = NULL;
	solve_66(list_a, list_b);
	clear_list(list_a);
	(*list_a) = setup(argc, argv);
	(*list_b) = NULL;
	solve_75(list_a, list_b);
	clear_list(list_a);
	(*list_a) = setup(argc, argv);
	(*list_b) = NULL;
	solve_99(list_a, list_b);
	print_best_method();
}
