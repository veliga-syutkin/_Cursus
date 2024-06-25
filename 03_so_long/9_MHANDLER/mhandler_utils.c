/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:05:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 18:35:59 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mhandler.h"

/*
  Returns a pointer to the last element of chained list of elements with 
memory allocated.
*/
t_allocs	*get_last(t_allocs **allocs)
{
	t_allocs	*temp;

	temp = *allocs;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

/*
  Returns a pointer to element with given ID.
*/
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
