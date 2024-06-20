/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:09:42 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/13 17:38:01 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// checks and returns state of list
static
int	list_state(t_list *list)
{
	int	nb1;
	int	nb2;
	int	nb3;

	if (!list || !list->next || !list->next->next)
		return (-1);
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

// solves list a with 3 elements
void	solve_3(t_list **list)
{
	int		state;

	state = list_state(*list);
	if (state == 132 || state == 321 || state == 213)
		sa(list);
	if (state == 312 || state == 132)
		ra(list);
	if (state == 231 || state == 321)
		rra(list);
}

// solves list b with 3 elements
void	solve_3b(t_list **list)
{
	int		state;

	state = list_state(*list);
	if (state == 231 || state == 123 || state == 312)
		sb(list);
	if (state == 132 || state == 312)
		rb(list);
	if (state == 213 || state == 123)
		rrb(list);
}
