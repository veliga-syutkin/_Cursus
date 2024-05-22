/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:01 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/22 16:39:12 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "mhandler.h"

t_allocs	*mhandler_init(void)
{
	t_allocs	*allocs;

	allocs = (t_allocs *)malloc(sizeof(t_allocs));
	if (!allocs)
		ft_error(ERR_ALLOC, NULL);
	allocs->id = 0;
	allocs->content = NULL;
	allocs->next = NULL;
	return (allocs);
}

void	mhandler_add(t_allocs **allocs, void *content)
{
	t_allocs	*new;
	t_allocs	*temp;

	new = (t_allocs *)malloc(sizeof(t_allocs));
	if (!new)
		ft_error(ERR_ALLOC, NULL);
	new->id = (*allocs)->id + 1;
	new->content = content;
	new->next = NULL;
	temp = *allocs;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	mhandler_free_all(t_allocs **allocs)
{
	t_allocs	*temp;

	while (*allocs)
	{
		temp = (*allocs)->next;
		free((*allocs)->content);
		free(*allocs);
		*allocs = temp;
	}
}

void	mhandler_free_one(int id, t_allocs **allocs)
{
	t_allocs	*temp;
	t_allocs	*prev;

	temp = *allocs;
	prev = NULL;
	while (temp)
	{
		if (temp->id == id)
			break ;
		prev = temp;
		temp = temp->next;
	}
	if (!prev)
	{
		temp = temp->next;
		free(temp->content);
		free(temp);
		*allocs = temp;
	}
	else
	{
		prev->next = temp->next;
		free(temp->content);
		free(temp);
	}
}
