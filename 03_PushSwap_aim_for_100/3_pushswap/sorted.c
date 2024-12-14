/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:56:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 03:07:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// checks if given list is sorted from smallest to largest
bool	sorted(t_list *list)
{
	while (list->next && list->data < list->next->data)
		list = list->next;
	list = list->next;
	if (!list)
		return (true);
	return (false);
}

// probably DEPRECATED
// checks if list is reverse sorted from largest to smallest
bool	reverse_sorted(t_list *list)
{
	while (list->next && list->data > list->next->data)
		list = list->next;
	list = list->next;
	if (!list)
		return (true);
	return (false);
}
