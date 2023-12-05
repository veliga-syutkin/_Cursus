/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:11:21 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 14:28:00 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//The last element becomes the last one, shifting down all elements by 1.
void	reverse(t_stack **stack)
{
	t_stack	*tmp;

	tmp = ft_lstlast(*stack);
	ft_lstadd_front(stack, tmp);
	ft_lstdelone(tmp, free);
}

//The last element becomes the last one, 
// shifting down all elements by 1 in 2 stacks.
void	reverses(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}
