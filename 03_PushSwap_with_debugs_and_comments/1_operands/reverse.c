/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:40:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 07:37:51 by vsyutkin         ###   ########.fr       */
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
	ft_printf("rrr\n");
	print_percentage();
	// add_instruction(RRR);
}

void	rra(t_list **list)
{
	rrx(list);
	ft_printf("rra\n");
	print_percentage();
	// add_instruction(RRA);
}

void	rrb(t_list **list)
{
	rrx(list);
	ft_printf("rrb\n");
	print_percentage();
	// add_instruction(RRB);
}
