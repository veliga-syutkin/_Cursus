/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:25:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 17:04:53 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H


/*
Value: value of the element
Next: pointer to the next element
Prev: pointer to the previous element
Pos_end: position of the element in the final stack
Link: if the element is linked to min or max element
Start: pointer to the first element of the stack
End: pointer to the last element of the stack
*/

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