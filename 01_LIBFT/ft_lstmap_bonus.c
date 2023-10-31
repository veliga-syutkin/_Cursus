/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/24 15:57:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstclear_null(t_list **lst, void (*del)(void*), void *postop)
{
	t_list	*tmp;

	free (postop);
	if (!del || !lst || !(void *)lst)
		return (NULL);
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	return (NULL);
}

// Iterates on list, applies f function to every content, 
// Creates a new list from every f application. 
// Del function is here for destroy an element if needs to.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last;
	t_list	*new_elem;
	void	*postop;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		postop = (*f)(lst->content);
		if (postop)
		{
			new_elem = ft_lstnew(postop);
			if (!new_elem)
				return (ft_lstclear_null(&new_list, del, postop));
			if (!new_list)
				new_list = new_elem;
			else
				last->next = new_elem;
			last = new_elem;
		}
		lst = lst->next;
	}
	return (new_list);
}
