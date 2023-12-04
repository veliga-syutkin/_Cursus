/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:30:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 15:36:48 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./0_LIBFT/libft.h"

void	pos_end(t_stack **stack);

typedef struct s_order
{
	int				value;
	int				order;
	struct s_order	*next;
}		t_order;



#endif