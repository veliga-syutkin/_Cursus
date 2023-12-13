/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:09:42 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/13 17:05:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static
int	list_state(t_list *list)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = list->data;
	nb2 = list->next->data;
	nb3 = list->next->next->data;
	if (nb3 > nb1 && nb1 > nb2)
		return (213);
	else if (nb1 > nb2 && nb2 > nb3)
		return (321);
	else if (nb1 > nb3 && nb3 > nb2)
		return (312);
	else if (nb2 > nb3 && nb3 > nb1)
		return (132);
	else if (nb2 > nb1 && nb1 > nb3)
		return (231);
	return (123);
}

void	solve_3(t_list **list)
{
	int		state;

	state = list_state(*list);
	if (state == 132 || state == 321 || state == 213)
	{
		sx(list);
		write(1, "sa\n", 3);
	}
	if (state == 312 || state == 132)
	{
		rx(list);
		write(1, "ra\n", 3);
	}
	if (state == 231 || state == 321)
	{
		rrx(list);
		write(1, "rra\n", 4);
	}
}
