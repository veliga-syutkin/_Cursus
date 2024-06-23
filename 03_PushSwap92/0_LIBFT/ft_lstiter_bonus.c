/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:31 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 10:28:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates on list element and applies f function to each element.
void	ft_lstiter(t_stack *lst, void (*f)(void *))
{
	while (lst && f)
	{
		lst = lst->next;
	}
}
