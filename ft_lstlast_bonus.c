/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:33 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/25 09:41:28 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns last element of list
t_list	*ft_lstlast(t_list *lst)
{
	int	end;

	end = FALSE;
	while (end != TRUE && lst)
	{
		if (lst->next != NULL)
			lst = lst->next;
		else
			end = TRUE;
	}
	return (lst);
}
