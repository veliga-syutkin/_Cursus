/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:05:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/23 22:05:58 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mhandler.h"

t_allocs	*get_last(t_allocs **allocs)
{
	t_allocs	*temp;

	temp = *allocs;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

t_allocs	*get_id(t_allocs **allocs, void *id)
{
	t_allocs	*temp;

	temp = *allocs;
	while (temp)
	{
		if (temp->id == id)
			return (temp);
		temp = temp->next;
	}
	return (0);
}
