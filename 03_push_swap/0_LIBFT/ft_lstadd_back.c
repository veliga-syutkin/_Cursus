/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:49:29 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 16:28:55 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// add element *new at the end of list
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
}

// Returns last element of list
t_order	*lstlast(t_order *lst)
{
	bool	end;

	end = false;
	while (end != true && lst)
	{
		if (lst->next != NULL)
			lst = lst->next;
		else
			end = true;
	}
	return (lst);
}

// add element *new at the end of list
void	lstadd_back(t_order **lst, t_order *new)
{
	t_order	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = lstlast(*lst);
	tmp->next = new;
}
