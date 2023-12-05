/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:49:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 13:54:56 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Take the first element of stack_FROM and put it at the top of stack_TO
//Do nothing if stack_A is empty.
void	push(t_stack **from, t_stack **to)
{
	t_stack *tmp;

	tmp = *from;
	ft_lstadd_front(to, tmp);
	ft_lstdelone(tmp, free);
}
