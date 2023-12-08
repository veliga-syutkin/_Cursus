/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:11:21 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/08 16:18:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//The last element becomes the first one, shifting down all elements by 1.
void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	int		value;
	int		end;

	if (!*stack)
		return ;
	tmp = *stack;
	tmp->prev = NULL;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	checkpoint(1000);
	value = tmp->value;
	end = tmp->pos_end;
	while (tmp->prev)
	{
		tmp->value = tmp->prev->value;
		tmp->pos_end = tmp->prev->pos_end;
		tmp = tmp->prev;
	}
	checkpoint(1001);
	tmp->value = value;
	tmp->pos_end = end;
}

//The last element becomes the last one, 
// shifting down all elements by 1 in 2 stacks.
void	reverses(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_lstupdate_both(stack_a, stack_b);
}
