/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:19:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/13 17:00:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_b)
	{
		buffer = (*list_b)->next;
		(*list_b)->next = (*list_a);
		(*list_a) = (*list_b);
		(*list_b) = buffer;
	}
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_a)
	{
		buffer = (*list_a)->next;
		(*list_a)->next = (*list_b);
		(*list_b) = (*list_a);
		(*list_a) = buffer;
	}
}

void	pax(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_b)
	{
		buffer = (*list_b)->next;
		(*list_b)->next = (*list_a);
		(*list_a) = (*list_b);
		(*list_b) = buffer;
		if (flag_method(0, 0) == STDOUT)
			ft_printf("pa\n");
		else
			methods(WRITE, flag_method(0, 0), ft_strdup(PA));
	}
}

void	pbx(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_a)
	{
		buffer = (*list_a)->next;
		(*list_a)->next = (*list_b);
		(*list_b) = (*list_a);
		(*list_a) = buffer;
		if (flag_method(0, 0) == STDOUT)
			ft_printf("pb\n");
		else
			methods(WRITE, flag_method(0, 0), ft_strdup(PB));
	}
}
