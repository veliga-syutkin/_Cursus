/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/24 05:00:01 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	print_instructions_t(int instruction)
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

int	optimization_result(int flag)
{
	static unsigned int	count;

	if (flag)
		count += flag;
	return (count);
}
