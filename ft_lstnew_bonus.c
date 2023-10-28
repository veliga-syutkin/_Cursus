/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/25 09:46:06 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocs and returns new t_list element. 
// 	Content goes content, next goes NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *) malloc (sizeof(t_list) * 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

/*OVERPROTECTED
t_list *ft_lstnew(void *content)
{
	t_list	*list;

	if (!content)
		return (NULL);
	list = (t_list *) malloc (sizeof(t_list) * 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}*/