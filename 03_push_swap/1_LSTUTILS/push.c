/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:49:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/08 15:53:22 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Take the first element of stack_FROM and put it at the top of stack_TO
//Do nothing if stack_A is empty.
void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;
	int		end;
	int		value;

	if (!from)
		return ;
	end = (*from)->pos_end;
	value = (*from)->value;
	tmp = ft_lstnew(value);
	tmp->pos_end = end;
	if (!*to)
	{
		checkpoint(20);
		*to = tmp;
	}
	else
	{
		checkpoint(30);
		tmp->next = *to;
		*to = tmp;
	}
	ft_delfirst(from, free);
	ft_lstupdate_both(from, to);
}

