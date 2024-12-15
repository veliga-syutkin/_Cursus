/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:05:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/15 01:52:16 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mhandler.h"

/*
  Free the allocated memory.
*/
static void	mhandler_free_1d_or_2d(t_allocs *allocs)
{
	if (allocs->is_2d)
	{
		if (allocs->content_2d)
			free(allocs->content_2d);
	}
	else
		if (allocs->content)
			free(allocs->content);
}

/*
  Free all elements in the list of allocated elements.
*/
void	mhandler_free_all(t_allocs **allocs)
{
	t_allocs	*temp;

	while (*allocs)
	{
		temp = (*allocs)->next;
		mhandler_free_1d_or_2d(*allocs);
		(*allocs)->content = NULL;
		free(*allocs);
		*allocs = temp;
	}
}

void	mhandler_free_all_rev(t_allocs **allocs)
{
	t_allocs	*current;
	t_allocs	*prev;

	if (!allocs || !*allocs)
		return ;
	current = *allocs;
	while (current->next)
		current = current->next;
	while (current)
	{
		prev = *allocs;
		mhandler_free_1d_or_2d(current);
		current->content = NULL;
		free(current);
		while (prev && prev->next != current)
			prev = prev->next;
		current = prev;
	}
	*allocs = NULL;
}

/*
  Free one element ID in the list of allocated elements.
*/
void	mhandler_free_by_func_ptr(void *func_ptr, t_allocs **allocs)
{
	t_allocs	*temp;
	t_allocs	*prev;

	temp = *allocs;
	prev = NULL;
	while (temp)
	{
		if (temp->func_ptr == func_ptr)
			break ;
		prev = temp;
		temp = temp->next;
	}
	if (!prev)
	{
		temp = temp->next;
		mhandler_free_1d_or_2d(temp);
		free(temp);
		*allocs = temp;
	}
	else
	{
		prev->next = temp->next;
		mhandler_free_1d_or_2d(temp);
		free(temp);
	}
}
