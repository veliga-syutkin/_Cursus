/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/21 00:16:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates on list element and applies f function to each element.
void	ft_lstiter(t_stack *lst, void (*f)(void *))
{
	while (lst && f)
	{
		// f(lst->content);
		lst = lst->next;
	}
}
