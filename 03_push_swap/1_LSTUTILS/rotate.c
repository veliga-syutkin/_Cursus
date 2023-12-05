/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:55:30 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 14:28:22 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Put first element becomes last one, shifting up all elements of stack by 1.
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	ft_lstadd_back(stack, tmp);
	ft_lstdelone(tmp, free);
}

//First element of 2 stacks become last one,
//shifting up all elements of stacks by 1.
void	rotates(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
