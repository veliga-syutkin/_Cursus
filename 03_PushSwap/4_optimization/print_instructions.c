/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/24 05:02:38 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	optimize_instructions_opposite(int *a)
{
	int	cursor;

	cursor = 0;
	while (cursor < 20000 - 1)
	{
		if ((a[cursor] == RRA && a[cursor + 1] == RRB)
			|| (a[cursor] == RRB && a[cursor + 1] == RRA))
		{
			a[cursor] = RRR;
			a[cursor + 1] = BLANK;
			optimization_result(1);
		}
		if ((a[cursor] == RA && a[cursor + 1] == RB)
			|| (a[cursor] == RB && a[cursor + 1] == RA))
		{
			a[cursor] = RR;
			a[cursor + 1] = BLANK;
			optimization_result(1);
		}
		cursor++;
	}
}

void	optimize_instructions_redundant(int *a)
{
	int	cursor;

	cursor = 0;
	while (cursor < 20000 - 1)
	{
		if ((a[cursor] == RA && a[cursor + 1] == RRA)
			|| (a[cursor] == RRA && a[cursor + 1] == RA))
		{
			a[cursor] = BLANK;
			a[cursor + 1] = BLANK;
			optimization_result(2);
		}
		if ((a[cursor] == RB && a[cursor + 1] == RRB)
			|| (a[cursor] == RRB && a[cursor + 1] == RB))
		{
			a[cursor] = BLANK;
			a[cursor + 1] = BLANK;
			optimization_result(2);
		}
		cursor++;
	}
}

void	print_instructions(int *a)
{
	int	cursor;

	cursor = 0;
	while (a[cursor] != 0 && cursor < 20000)
	{
		print_instructions_t(a[cursor]);
		if (a[cursor] != BLANK)
			print_percentage();
		cursor++;
	}
	ft_printf("\nInstructions cleaned: %d\n", optimization_result(0));
}

//	Print list of instructions as long as progress of steps done (each 5%).
int	*string_instruction(int move, int flag)
{
	static int	instructions[20000];
	static int	i;

	if (flag == WRITE)
		instructions[i++] = move;
	if (flag == END)
	{
		i = 0;
		while (instructions[i] && i < 20000)
			instructions[i] = 0;
	}
	if (flag == OPTI)
	{
		optimize_instructions_opposite(instructions);
		optimize_instructions_redundant(instructions);
	}
	return (instructions);
}

void	add_instruction(int instruction)
{
	string_instruction(instruction, WRITE);
}
