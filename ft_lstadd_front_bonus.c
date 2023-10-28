/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:24 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/25 10:09:16 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  Add element *new at the start of list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* OVERPROTECTED, I guess (as paco said)
void	ft_lstadd_front(t_list **lst, t_list *new)
{
//	if (lst && *lst)
//	{
		new->next = *lst;
		*lst = new;
//	}
}*/
