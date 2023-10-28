/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/25 09:42:41 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts list size (number of elements lists)
int	ft_lstsize(t_list *lst)
{
	int	count;
	int	end;

	count = 0;
	end = FALSE;
	while (end != TRUE && lst)
	{
		count++;
		if (lst->next != NULL)
			lst = lst->next;
		else
			end = TRUE;
	}
	return (count);
}
