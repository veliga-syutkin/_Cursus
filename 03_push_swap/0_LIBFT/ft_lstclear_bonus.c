/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:27:15 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 16:37:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Frees and deletes passed list and also the following lists.
// Sets inital pointer to NULL. 
void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

// Sets inital pointer to NULL. 
void	lstclear(t_order **lst, void (*del)(void*))
{
	t_order	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		lstdelone(*lst, del);
		*lst = tmp;
	}
}
