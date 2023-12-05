/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:55:30 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 16:35:19 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Put first element becomes last one, shifting up all elements of stack by 1.
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	int		value;

	tmp = *stack;
	value = tmp->value;
	last = ft_lstlast(*stack);
	ft_lstadd_back(stack, tmp);
	ft_delfirst(stack, free);
	last = last->next;
	last->value = value;
	last->next = NULL;
}

//First element of 2 stacks become last one,
//shifting up all elements of stacks by 1.
void	rotates(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
