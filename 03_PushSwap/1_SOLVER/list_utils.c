/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:48:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/13 14:54:28 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *list)
{
	int	max;

	max = list->data;
	while (list)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

int	find_min(t_list *list)
{
	int	min;

	min = list->data;
	while (list)
	{
		if (list->data < min)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	get_len(t_list *list)
{
	int len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

int	get_last_data(t_list *list, int offset)
{
	int	cursor;
	int	len;

	cursor = 1;
	len = get_len(list);
	while (list->next && cursor < len - offset)
	{
		list = list->next;
		cursor++;
	}
	return (list->data);
}

void	reset_and_pb(t_list **list_a, t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rx(list_b);
		ft_putstr_fd("rb\n", 1);
	}
	pb(list_a, list_b);
	ft_putstr_fd("pb\n", 1);
}
