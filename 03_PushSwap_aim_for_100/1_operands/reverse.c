/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:40:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/13 15:16:23 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rrx(t_list **list)
{
	t_list	*buffer;

	buffer = (*list);
	if (!buffer || !buffer->next)
		return ;
	while (buffer->next->next)
		buffer = buffer->next;
	buffer->next->next = (*list);
	(*list) = buffer->next;
	buffer->next = NULL;
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rrx(list_a);
	rrx(list_b);
	if (flag_method(0, 0) == STDOUT)
		ft_printf("rrr\n");
	else
		methods(WRITE, flag_method(0, 0), RRR);
}

void	rra(t_list **list)
{
	rrx(list);
	if (flag_method(0, 0) == STDOUT)
		ft_printf("rra\n");
	else
		methods(WRITE, flag_method(0, 0), RRA);
}

void	rrb(t_list **list)
{
	rrx(list);
	if (flag_method(0, 0) == STDOUT)
		ft_printf("rrb\n");
	else
		methods(WRITE, flag_method(0, 0), RRB);
}
