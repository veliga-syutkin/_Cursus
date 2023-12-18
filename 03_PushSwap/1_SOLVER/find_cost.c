/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:47:58 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/18 02:36:12 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculates the cost of "reverse rotate b"
int	cost_to_reset_rrb(t_list *list)
{
	int	cost;

	while (list->next && list->data > list->next->data)
		list = list->next;
	if (!list->next)
		return (0);
	cost = 0;
	while (list->next)
	{
		list = list->next;
		cost++;
	}
	return (cost);
}

// calculates the cost of "rotate b"
int	cost_to_reset_rb(t_list *list)
{
	int	cost;

	cost = 0;
	while (list->next && list->data > list->next->data)
	{
		list = list->next;
		cost++;
	}
	if (!list->next)
		return (0);
	return (cost);
}

int	find_cost_rb(t_list *element, t_list *list_b)
{
	int	first;
	int	last;
	int	cost;

	if (element->data > find_max(list_b) || element->data < find_min(list_b))
	{
		if (cost_to_reset_rb(list_b) < cost_to_reset_rrb(list_b))
			return (cost_to_reset_rb(list_b));
		return (cost_to_reset_rrb(list_b));
	}
	cost = 0;
	first = list_b->data;
	last = get_last_data(list_b, 0);
	while (element->data < first || element->data > last)
	{
		last = first;
		first = get_next_data(list_b, first);
		cost++;
	}
	return (cost);
}

int	find_cost_rrb(t_list *element, t_list *list_b)
{
	int	first;
	int	last;
	int	cost;

	if (element->data > find_max(list_b) || element->data < find_min(list_b))
	{
		if (cost_to_reset_rb(list_b) < cost_to_reset_rrb(list_b))
			return (cost_to_reset_rb(list_b));
		return (cost_to_reset_rrb(list_b));
	}
	cost = 0;
	first = list_b->data;
	last = get_last_data(list_b, 0);
	while (element->data < first || element->data > last)
	{
		first = last;
		last = get_last_data(list_b, ++cost);
	}
	return (cost);
}
