/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 16:12:37 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Frees memory of lst, deletes the node form chain list. 
// Uses function *del to proper delete the content. 
void	ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	if (lst)
	{
//		(del)(lst->value);
		free(lst);
	}
}

// Frees memory of lst, deletes the node form chain list. 
// Uses function *del to proper delete the content. 
void	lstdelone(t_order *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	if (lst)
	{
//		(*del)(*lst->value);
		free(lst);
	}
}
//like delone, but for the first element of the chained list.
void	ft_delfirst(t_stack **head, void (*del)(void*))
{
	t_stack	*to_delete;

	to_delete = *head;
	*head = to_delete->next;
	ft_lstdelone(to_delete, (*del));
}
