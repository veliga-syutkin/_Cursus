/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/10/29 19:54:33 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts list size (number of elements lists)
int	ft_lstsize(t_list *lst)
{
	int		count;
	bool	end;

	count = 0;
	end = false;
	while (end != true && lst)
	{
		count++;
		if (lst->next != NULL)
			lst = lst->next;
		else
			end = true;
	}
	return (count);
}
