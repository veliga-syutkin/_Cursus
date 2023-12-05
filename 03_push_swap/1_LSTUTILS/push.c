/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:49:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 21:11:59 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Take the first element of stack_FROM and put it at the top of stack_TO
//Do nothing if stack_A is empty.
void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;
	int		end;

	if (!from)
		return ;
	tmp = *from;
	end = tmp->pos_end;
	tmp = ft_lstnew(tmp->value);
	tmp->next = NULL;
	tmp->pos_end = end;
	ft_delfirst(from, free);
	if (!*to)
	{
		checkpoint(20);
		*to = tmp;
	}
	else
	{
		checkpoint(30);
		// tmp->next = *to;
		*to = tmp;
		tmp = *to;
	}
	ft_lstupdate_both(from, to);
}
