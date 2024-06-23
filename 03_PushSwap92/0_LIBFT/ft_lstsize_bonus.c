/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:40 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/27 05:17:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts list size (number of elements lists)
int	ft_lstsize(t_stack *lst)
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
