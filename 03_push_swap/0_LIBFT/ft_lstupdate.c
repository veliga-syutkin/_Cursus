/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstupdate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:35:21 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/08 16:21:56 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

/*This function will update all lst->prev links*/
void	ft_lstupdate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*end;

	end = ft_lstlast(*stack);
	tmp = *stack;
	tmp2 = tmp;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp)
		{
			tmp->prev = tmp2;
			tmp->start = (*stack);
			tmp->end = end;
		}
	}
}

/*Updates ->prev links in both stacks*/
void	ft_lstupdate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstupdate(stack_a);
	ft_lstupdate(stack_b);
}
