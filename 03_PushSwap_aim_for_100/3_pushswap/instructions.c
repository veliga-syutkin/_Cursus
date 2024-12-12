/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:59:03 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/12 16:49:21 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// [ DEPRECATED ]
static void	ft_print_instruction(int instruction)
{
	if (instruction == SA)
		ft_putstr_fd("sa\n", 1);
	if (instruction == SB)
		ft_putstr_fd("sb\n", 1);
	if (instruction == SS)
		ft_putstr_fd("ss\n", 1);
	if (instruction == PA)
		ft_putstr_fd("pa\n", 1);
	if (instruction == PB)
		ft_putstr_fd("pb\n", 1);
	if (instruction == RA)
		ft_putstr_fd("ra\n", 1);
	if (instruction == RB)
		ft_putstr_fd("rb\n", 1);
	if (instruction == RR)
		ft_putstr_fd("rr\n", 1);
	if (instruction == RRA)
		ft_putstr_fd("rra\n", 1);
	if (instruction == RRB)
		ft_putstr_fd("rrb\n", 1);
	if (instruction == RRR)
		ft_putstr_fd("rrr\n", 1);
}

// [ DEPRECATED ]
t_stack	**instruction(int flag)
{
	static t_stack	*instruction;
	t_stack			*buffer;
	t_stack			*buffer_next;

	if (flag == 0)
	{
		instruction = ft_lstnew(2);
	}
	if (flag == -1)
	{
		if (instruction)
		{
			buffer = instruction;
			while (buffer->next)
			{
				buffer_next = buffer->next;
				free(buffer);
				buffer = buffer_next;
			}
			free(buffer);
		}
	}
	return (&instruction);
}

// [ DEPRECATED ]
void	ft_lstprint_and_free(t_stack **instructions)
{
	t_stack	*temp;

	temp = *instructions;
	while (temp->next)
	{
		ft_print_instruction(temp->content);
		temp = temp->next;
	}
	instruction(-1);
}
