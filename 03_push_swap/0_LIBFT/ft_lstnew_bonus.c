/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 16:09:31 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocs and returns new t_stack element. 
// 	value goes value, next goes NULL.
t_stack	*ft_lstnew(int value)
{
	t_stack	*list;

	list = (t_stack *) malloc (sizeof(t_stack) * 1);
	if (!list)
		return (NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}

t_order	*lstnew(int value)
{
	t_order	*list;

	list = (t_order *) malloc (sizeof(t_order) * 1);
	if (!list)
		return (NULL);
	list->value = value;
	list->next = NULL;
	return (list);
}
