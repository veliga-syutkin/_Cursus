/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:01 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/24 18:42:35 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mhandler.h"
#include "../0_LIBFT/libft.h"

t_allocs	*mhandler_init(void *content, void *id)
{
	t_allocs	*head_allocs;

	head_allocs = (t_allocs *)malloc(sizeof(t_allocs));
	if (!head_allocs)
	{
		ft_printf(ERR_ALLOC);
		exit(EXIT_FAILURE);
	}
	head_allocs->id = id;
	head_allocs->content = content;
	head_allocs->next = NULL;
	return (head_allocs);
}

void	mhandler_add(t_allocs **allocs, void *content, void *id)
{
	t_allocs	*new;
	t_allocs	*temp;

	if (!(*allocs))
	{
		(*allocs) = mhandler_init(content, id);
		return ;
	}
	new = (t_allocs *)malloc(sizeof(t_allocs));
	if (!new)
	{
		ft_printf(ERR_ALLOC);
		mhandler_free_all(allocs);
		exit(EXIT_FAILURE);
	}
	temp = *allocs;
	while (temp->next)
		temp = temp->next;
	new->id = id;
	new->content = content;
	new->next = NULL;
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

void	mhandler_free_one(void *id, t_allocs **allocs)
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
