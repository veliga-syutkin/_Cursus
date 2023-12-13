/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:14:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/13 16:16:01 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **list_a, t_list **list_b)
{
	sx(list_a);
	sx(list_b);
}

void	sx(t_list **list)
{
	t_list	*buffer;

	if (list && *list && (*list)->next)
	{
		buffer = (*list)->next;
		(*list)->next = (*list)->next->next;
		buffer->next = (*list);
		(*list) = buffer;
	}
}
