/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:33 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 19:05:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns last element of list
t_list	*ft_lstlast(t_list *lst)
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
