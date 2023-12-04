/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstupdate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:35:21 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 12:13:17 by vsyutkin         ###   ########.fr       */
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
