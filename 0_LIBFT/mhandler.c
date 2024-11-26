/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:01 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/08/20 21:46:01 by aalferov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mhandler.h"

/*
  Initialize the list of allocated elements.
*/
static t_allocs	*mhandler_init(void *content, void **content2d, void *func_ptr)
{
	t_allocs	*head_allocs;

	head_allocs = (t_allocs *)malloc(sizeof(t_allocs));
	if (!head_allocs)
	{
		ft_printf(ERR_ALLOC);
		if (content)
			free(content);
		exit(EXIT_FAILURE);
	}
	head_allocs->func_ptr = func_ptr;
	if (content2d)
	{
		head_allocs->content_2d = content2d;
		head_allocs->is_2d = true;
	}
	else
	{
		head_allocs->content = content;
		head_allocs->is_2d = false;
	}
	head_allocs->content = content;
	head_allocs->next = NULL;
	return (head_allocs);
}

/*
  Add new *element to the end of the list of allocated elements.
*/
void	mhandler_add(t_allocs **allocs, void *content, void *func_ptr)
{
	t_allocs	*new;
	t_allocs	*temp;

	if (!(*allocs))
	{
		(*allocs) = mhandler_init(content, NULL, func_ptr);
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
	new->func_ptr = func_ptr;
	new->content = content;
	new->is_2d = false;
	new->next = NULL;
	temp->next = new;
}

/*
  Add new *`2d`element to the end of the list of allocated elements.
+ DO NOT FORGET TO CAST AS `(void **)` WHEN CALLING THIS FUNCTION
*/
void	mhandler_add_2d(t_allocs **allocs, void **content, void *func_ptr)
{
	t_allocs	*new;
	t_allocs	*temp;

	if (!(*allocs))
	{
		(*allocs) = mhandler_init(NULL, content, func_ptr);
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
	new->func_ptr = func_ptr;
	new->content_2d = content;
	new->is_2d = true;
	new->next = NULL;
	temp->next = new;
}
