/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:25:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:48 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				pos_end;
	bool			link;
	struct s_stack	*start;
	struct s_stack	*end;
}					t_stack;

typedef struct s_order
{
	int				value;
	int				order;
	struct s_order	*next;
}		t_order;

#endif