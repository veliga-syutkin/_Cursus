/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:30:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 15:11:26 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./0_LIBFT/libft.h"

void	pos_end(t_stack **stack);
void	ft_print_stack(t_stack **stack);

// -._.-""-._OPERATIONS_.-""-._.-

void	swap(t_stack **stack);
void	swaps(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	rotates(t_stack **stack_a, t_stack **stack_b);
void	reverse(t_stack **stack);
void	reverses(t_stack **stack_a, t_stack **stack_b);

//########### DEBUG ###########

void	checkpoint(int x);

#endif