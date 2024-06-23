/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:56:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 15:32:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// probably DEPRECATED
// checks if list is sorted
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
// checks if list is reverse sorted
bool	reverse_sorted(t_list *list)
{
	while (list->next && list->data > list->next->data)
		list = list->next;
	list = list->next;
	if (!list)
		return (true);
	return (false);
}
