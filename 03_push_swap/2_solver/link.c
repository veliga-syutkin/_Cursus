/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:30:49 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/08 16:39:00 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static
void	linker_single(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->next && tmp->link == false)
			if (tmp->pos_end == tmp->next->pos_end - 1 || tmp->pos_end == tmp->next->pos_end + 1)
				tmp->link = true;
		else if (tmp->prev && tmp->link == false)
			if (tmp->pos_end == tmp->prev->pos_end - 1 || tmp->pos_end == tmp->prev->pos_end + 1)
				tmp->link = true;
		tmp = tmp->next;
	}
}

void	linker(t_stack **stack_a, t_stack **stack_b)
{
	linker_single(stack_a);
	linker_single(stack_b);
}
