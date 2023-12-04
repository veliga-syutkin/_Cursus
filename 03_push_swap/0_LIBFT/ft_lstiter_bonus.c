/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 13:56:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates on list element and applies f function to each element.
void	ft_lstiter(t_stack *lst, void (*f)(void *))
{
	while (lst && f)
	{
//		f(lst->value);
		lst = lst->next;
	}
}
