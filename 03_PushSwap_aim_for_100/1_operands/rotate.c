/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:23:38 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/13 17:01:37 by vsyutkin         ###   ########.fr       */
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
	if (flag_method(0, 0) == STDOUT)
		ft_printf("rr\n");
	else
		methods(WRITE, flag_method(0, 0), ft_strdup(RR));
}

void	ra(t_list **list)
{
	rx(list);
	if (flag_method(0, 0) == STDOUT)
		ft_printf("ra\n");
	else
		methods(WRITE, flag_method(0, 0), ft_strdup(RA));
}

void	rb(t_list **list)
{
	rx(list);
	if (flag_method(0, 0) == STDOUT)
		ft_printf("rb\n");
	else
		methods(WRITE, flag_method(0, 0), ft_strdup(RB));
}
