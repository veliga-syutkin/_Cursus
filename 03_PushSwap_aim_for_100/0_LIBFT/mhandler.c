/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:01 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/12 18:27:53 by vsyutkin         ###   ########.fr       */
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
		ft_putendl_fd(MHANDLER_ERR_ALLOC, 2);
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

  + [DEPRECATED], use `mhandler_check` instead.
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
		ft_putendl_fd(MHANDLER_ERR_ALLOC, 2);
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

  + [DEPRECATED], use `mhandler_check` instead.
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
		ft_putendl_fd(MHANDLER_ERR_ALLOC, 2);
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

/*	Checks if the content is NULL.
	+ If not, adds it to the list of allocated elements.
	+ If it is NULL, prints an error message and frees all allocated memory.
	
	(Intended to be used instead of `mhandler_add`)
*/
void	mhandler_check(t_allocs **allocs, void *content, void *func_ptr)
{
	if (!content)
	{
		ft_putendl_fd(MHANDLER_CONTENT_NULL, 2);
		mhandler_free_all(allocs);
		exit(EXIT_FAILURE);
	}
	mhandler_add(allocs, content, func_ptr);
}

/*	+ DO NOT FORGET TO CAST AS `(void **)` WHEN CALLING THIS FUNCTION

Checks if the content is NULL.
	+ If not, adds it to the list of allocated elements.
	+ If it is NULL, prints an error message and frees all allocated memory.
	
	(Intended to be used instead of `mhandler_add_2d`)
*/
void	mhandler_check_2d(t_allocs **allocs, void **content, void *func_ptr)
{
	if (!content)
	{
		ft_putendl_fd(MHANDLER_CONTENT_NULL, 2);
		mhandler_free_all(allocs);
		exit(EXIT_FAILURE);
	}
	mhandler_add_2d(allocs, content, func_ptr);
}
