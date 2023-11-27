/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/27 05:17:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocs and returns new t_stack element. 
// 	Content goes content, next goes NULL.
t_stack	*ft_lstnew(void *content)
{
	t_stack	*list;

	list = (t_stack *) malloc (sizeof(t_stack) * 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
