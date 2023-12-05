/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:11:21 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 20:21:46 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//The last element becomes the first one, shifting down all elements by 1.
void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	// int		value;

	if (!*stack)
		return ;
	last = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != last && tmp->next)
		tmp = tmp->next;
	last->next = *stack;
	*stack = last;
	if (tmp->next == last)
		tmp->next = NULL;
	// ft_lstdelone(last, free);
	ft_lstupdate(stack);
}

//The last element becomes the last one, 
// shifting down all elements by 1 in 2 stacks.
void	reverses(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_lstupdate_both(stack_a, stack_b);
}
