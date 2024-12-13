/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:14:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/13 15:17:20 by vsyutkin         ###   ########.fr       */
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
	if (flag_method(0, 0) == STDOUT)
		ft_printf("ss\n");
	else
		methods(WRITE, flag_method(0, 0), SS);
}

void	sa(t_list **list)
{
	sx(list);
	if (flag_method(0, 0) == STDOUT)
		ft_printf("sa\n");
	else
		methods(WRITE, flag_method(0, 0), SA);
}

void	sb(t_list **list)
{
	sx(list);
	if (flag_method(0, 0) == STDOUT)
		ft_printf("sb\n");
	else
		methods(WRITE, flag_method(0, 0), SB);
}
