/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:50:45 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/08 16:58:45 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	solver(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b) && check_order(stack_a))
		return (true);
	else
	{
		
		solver(stack_a, stack_b);
	}
}
