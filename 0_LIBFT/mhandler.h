/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/10/24 12:39:29 by aalferov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MHANDLER_H
# define MHANDLER_H

# include "libft.h"
# include <stdio.h>

# define ERR_ALLOC "Operator... I'm not doing well lately...\
Check my physical integrity pretty please...\
(Error: Memory allocation failed)\n"

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

// typedef struct s_allocs_2d
// {
// 	void				*func_ptr;
// 	void				**content;
// 	struct s_allocs_2d	*next;
// }	t_allocs_2d;

void	mhandler_add(t_allocs **allocs, void *content, void *func_ptr);
void	mhandler_add_2d(t_allocs **allocs, void **content, void *func_ptr);
void	mhandler_free_all(t_allocs **allocs);
void	mhandler_free_by_func_ptr(void *func_ptr, t_allocs **allocs);

void	mhandler_free_all_rev(t_allocs **allocs);

// /* MHANDLER_2d */
// t_allocs_2d	*mhandler_init_2d_empty(void **content);
// void		mhandler_add_2d(t_allocs_2d **allc_2d, void **cont, void *f_ptr);
// void		mhandler_free_all_2d(t_allocs_2d **allc_2d);
// t_allocs_2d	*get_last_2d(t_allocs_2d **allc_2d);

#endif
