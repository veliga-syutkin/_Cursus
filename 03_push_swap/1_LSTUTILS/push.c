/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:49:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 16:58:13 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Take the first element of stack_FROM and put it at the top of stack_TO
//Do nothing if stack_A is empty.
void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;
	int		end;

	tmp = *from;
	end = tmp->pos_end;
	if (!from)
		return ;
	if (!*to)
	{
		checkpoint(2);
		*to = ft_lstnew(tmp->value);
		(*to)->pos_end = tmp->pos_end;
		ft_delfirst(from, free);
	}
	else
	{
		checkpoint(3);
		ft_lstadd_front(to, ft_lstnew(tmp->value));
		tmp = *to;
		tmp->pos_end = end;
		ft_delfirst(from, free);
	}
}
