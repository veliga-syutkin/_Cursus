/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:48:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/01 00:04:18 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// gets the max value in list
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

// gets the min value in list
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

// gets the length of list
int	get_len(t_list *list)
{
	int	len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

// gets the last data (value) in list
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

// puts lisb_b in order and pushes to b.
void	reset_and_pb(t_list **list_a, t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
		rb(list_b);
	pb(list_a, list_b);
}
