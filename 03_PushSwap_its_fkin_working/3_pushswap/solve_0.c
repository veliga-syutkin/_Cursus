/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:00:39 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 15:28:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/* finds cost of rotate*/
int	ft_find_rx(int data, t_list *list)
{
	int		cost_rx;
	int		cost_rrx;
	int		len;
	t_list	*last;

	len = get_len(list);
	last = list;
	while (last && last->next)
		last = last->next;
	cost_rx = 0;
	cost_rrx = 0;
	while (list)
	{
		if (data == list->data)
			break ;
		list = list->next;
		cost_rx++;
	}
	while (list)
	{
		list = list->next;
		cost_rrx++;
	}
	return (cost_rx);
}

// finds cost of reverse rotate
int	ft_find_rrx(int data, t_list *list)
{
	int		cost_rx;
	int		cost_rrx;
	int		len;
	t_list	*last;

	len = get_len(list);
	last = list;
	while (last && last->next)
		last = last->next;
	cost_rx = 0;
	cost_rrx = 0;
	while (list)
	{
		if (data == list->data)
			break ;
		list = list->next;
		cost_rx++;
	}
	while (list)
	{
		list = list->next;
		cost_rrx++;
	}
	return (cost_rrx);
}

// executes cheapest between ra and rra
void	maxmin_ra_or_rra(t_list **list, int data)
{
	int	cost_rx;
	int	cost_rrx;

	cost_rx = ft_find_rx(data, *list);
	cost_rrx = ft_find_rrx(data, *list);
	if (cost_rx <= cost_rrx)
		while (cost_rx--)
			ra(list);
	else
		while (cost_rrx--)
			rra(list);
}

// executes cheapest between rb and rrb
void	maxmin_rb_or_rrb(t_list **list, int data)
{
	int	cost_rx;
	int	cost_rrx;

	cost_rx = ft_find_rx(data, *list);
	cost_rrx = ft_find_rrx(data, *list);
	if (cost_rx <= cost_rrx)
		while (cost_rx--)
			rb(list);
	else
		while (cost_rrx--)
			rrb(list);
}

// main function to solve the problem
void	solve(t_list **list_a, t_list **list_b)
{
	int	max;

	max = find_max(*list_a);
	ft_start(list_a, list_b);
	while (get_len(*list_a) > 2)
	{
		weight_update(list_a, list_b);
		turk_move(list_a, list_b, data_min_weight(list_a));
		pbx(list_a, list_b);
	}
	maxmin_rb_or_rrb(list_b, find_max(*list_b));
	maxmin_ra_or_rra(list_a, find_min(*list_a));
	while (*list_b)
		ft_last_move(list_a, list_b);
	while ((*list_a)->data != find_min(*list_a))
		maxmin_ra_or_rra(list_a, find_min(*list_a));
}
