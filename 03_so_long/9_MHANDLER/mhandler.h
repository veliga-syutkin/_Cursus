/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mhandler.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/24 18:38:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MHANDLER_H
# define MHANDLER_H

# define ERR_ALLOC "Error\nMemory allocation failed\n"

typedef struct s_allocs
{
	void			*id;
	void			*content;
	struct s_allocs	*next;
}	t_allocs;

t_allocs	*mhandler_init(void *content, void *id);
void		mhandler_add(t_allocs **allocs, void *content, void *id);
void		mhandler_free_all(t_allocs **allocs);
void		mhandler_free_one(void *id, t_allocs **allocs);

t_allocs	*get_last(t_allocs **allocs);
t_allocs	*get_id(t_allocs **allocs, void *id);

#endif