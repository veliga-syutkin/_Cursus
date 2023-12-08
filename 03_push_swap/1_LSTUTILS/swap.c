/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:40:57 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/08 15:53:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Swap the first 2 elements of 1 given stack.
void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*top;
	int		value;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = *stack;
	top = tmp;
	value = tmp->value;
	tmp = tmp->next;
	top->value = tmp->value;
	tmp->value = value;
	ft_lstupdate(stack);
}

//Swap the first 2 elements of 2 given stacks.
void	swaps(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_lstupdate_both(stack_a, stack_b);
}
