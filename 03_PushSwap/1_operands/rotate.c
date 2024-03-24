/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:23:38 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/22 15:50:33 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rx(t_list **list)
{
	t_list	*buffer;

	buffer = (*list);
	if (!buffer || !buffer->next)
		return ;
	while (buffer->next)
		buffer = buffer->next;
	buffer->next = (*list);
	(*list) = (*list)->next;
	buffer->next->next = NULL;
}

void	rr(t_list **list_a, t_list **list_b)
{
	rx(list_a);
	rx(list_b);
	ft_printf("rr\n");
	print_percentage();
}

void	ra(t_list **list)
{
	rx(list);
	ft_printf("ra\n");
	print_percentage();
}

void	rb(t_list **list)
{
	rx(list);
	ft_printf("rb\n");
	print_percentage();
}
