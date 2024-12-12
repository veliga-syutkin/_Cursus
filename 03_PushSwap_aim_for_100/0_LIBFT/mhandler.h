/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/12 18:30:21 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MHANDLER_H
# define MHANDLER_H

# include "libft.h"
# include <stdio.h>

# define MHANDLER_ERR_ALLOC "MHANDLER: Error: Memory allocation failed\n"
# define MHANDLER_CONTENT_NULL "MHANDLER: Error: Content is NULL\n"

/*
  Structure for the list of allocated elements.
+ func_ptr: pointer to the function called memory allocation.
+ content: pointer to the allocated memory.
+ next: pointer to the next element in the list.
*/
typedef struct s_allocs
{
	void			*func_ptr;
	void			*content;
	void			**content_2d;
	bool			is_2d;
	struct s_allocs	*next;
}	t_allocs;

void	mhandler_check(t_allocs **allocs, void *content, void *func_ptr);
void	mhandler_check_2d(t_allocs **allocs, void **content, void *func_ptr);
void	mhandler_free_all(t_allocs **allocs);
void	mhandler_free_by_func_ptr(void *func_ptr, t_allocs **allocs);

void	mhandler_free_all_rev(t_allocs **allocs);

#endif
