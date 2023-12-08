/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:55:30 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/08 15:25:22 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Put first element becomes last one, shifting up all elements of stack by 1.
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		value;
	int		end;

	tmp = *stack;
	value = tmp->value;
	end = tmp->pos_end;
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp->pos_end = tmp->next->pos_end;
		tmp = tmp->next;
	}
	tmp->value = value;
	tmp->pos_end = end;
}

//First element of 2 stacks become last one,
//shifting up all elements of stacks by 1.
void	rotates(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_lstupdate_both(stack_a, stack_b);
}
