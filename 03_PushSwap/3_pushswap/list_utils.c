/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:48:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/22 10:38:53 by vsyutkin         ###   ########.fr       */
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
	while (list && list->next && cursor < len - offset)
	{
		list = list->next;
		cursor++;
	}
	return (list->data);
}

bool	order(t_list *list)
{
	while (list && list->next)
	{
		if (list->data > list->next->data)
			return (false);
		list = list->next;
	}
	return (true);
}
