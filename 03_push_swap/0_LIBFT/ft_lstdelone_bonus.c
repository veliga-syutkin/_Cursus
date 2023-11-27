/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 04:08:28 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/27 07:52:09 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Frees memory of lst, deletes the node form chain list. 
// Uses function *del to proper delete the content. 
void	ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	if (lst)
	{
		(*del)(lst->value);
		free(lst);
	}
}
