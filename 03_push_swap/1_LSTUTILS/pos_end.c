/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:42:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 13:35:32 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// t_stack visualization
void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	while (tmp)
	{
		ft_printf("%d, value: %d, pos_end: %d\n", i, tmp->value, tmp->pos_end);
		tmp = tmp->next;
		i++;
	}
}

//get chained list of given values in stack
t_order	*to_ordernot(t_stack **stack)
{
	t_order	*ordernot;
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	ordernot = lstnew(tmp_stack->value);
	tmp_stack = tmp_stack->next;
	while (tmp_stack)
	{
		lstadd_back(&ordernot, lstnew(tmp_stack->value));
		tmp_stack = tmp_stack->next;
	}
	return (ordernot);
}

//Find the order of elements after all operations.
void	sorter(t_order *toorder)
{
	t_order	*tmp_global;
	t_order	*tmp_local;
	int		tmp;

	tmp_global = toorder;
	tmp_local = toorder;
	while (tmp_global)
	{
		tmp_local = tmp_global->next;
		while (tmp_local)
		{
			if (tmp_global->value > tmp_local->value)
			{
				tmp = tmp_global->value;
				tmp_global->value = tmp_local->value;
				tmp_local->value = tmp;
			}
			tmp_local = tmp_local->next;
		}
		tmp_global = tmp_global->next;
	}
}

// give position of element in stack
void	order(t_order **toorder)
{
	t_order	*tmp;
	int		counter;

	tmp = *toorder;
	counter = 1;
	while (tmp)
	{
		tmp->order = counter;
		counter++;
		tmp = tmp->next;
	}
}

// Get's final position of each given number, first member is lowest among them
void	pos_end(t_stack **stack)
{
	t_order	*toorder;
	t_stack	*tmp_stack;
	t_order	*tmp_order;

	toorder = to_ordernot(stack);
	sorter(toorder);
	order(&toorder);
	tmp_stack = *stack;
	while (tmp_stack)
	{
		tmp_order = toorder;
		while (tmp_order)
		{
			if (tmp_stack->value == tmp_order->value)
			{
				tmp_stack->pos_end = tmp_order->order;
				break ;
			}
			tmp_order = tmp_order->next;
		}
		tmp_stack = tmp_stack->next;
	}
	lstclear(&toorder, free);
}
