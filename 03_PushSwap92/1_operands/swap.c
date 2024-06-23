/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:14:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 10:29:30 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sx(t_list **list)
{
	t_list	*buffer;

	if (list && *list && (*list)->next)
	{
		buffer = (*list)->next;
		(*list)->next = buffer->next;
		buffer->next = (*list);
		(*list) = buffer;
	}
}

void	ss(t_list **list_a, t_list **list_b)
{
	sx(list_a);
	sx(list_b);
	ft_printf("ss\n");
}

void	sa(t_list **list)
{
	sx(list);
	ft_printf("sa\n");
}

void	sb(t_list **list)
{
	sx(list);
	ft_printf("sb\n");
}
