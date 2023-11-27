/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:30:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/27 03:46:26 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./0_LIBFT/libft.h"

/*
Value: value of the element
Next: pointer to the next element
Prev: pointer to the previous element
Pos_end: position of the element in the final stack
Link: if the element is linked to min or max element
*/
typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack 	*prev;
	int				pos_end;
	bool			link;
}					t_stack;



#endif