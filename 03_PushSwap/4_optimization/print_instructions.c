/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:05 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/26 16:55:35 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	optimize_instructions_opposite(int *a)
{
	int	cursor;
	int	instruction;

	cursor = 0;
	instruction = 0;
	while (cursor < 20000 - 1)
	{
		instruction = cursor;
		while (a[instruction] == a[cursor] && cursor < 20000 - 1)
			cursor++;
		if ((a[instruction] == RRA && a[cursor] == RRB)
			|| (a[instruction] == RRB && a[cursor] == RRA))
		{
			a[instruction] = RRR;
			a[cursor] = BLANK;
			instruction++;
			optimization_result(1);
		}
		if ((a[instruction] == RA && a[cursor] == RB)
			|| (a[instruction] == RB && a[cursor] == RA))
		{
			a[instruction] = RR;
			a[cursor] = BLANK;
			instruction++;
			optimization_result(1);
		}
		cursor++;
	}
}

void	optimize_instructions_redundant(int *a)
{
	int	cursor;
	int	instruction;

	cursor = 0;
	instruction = 0;
	while (cursor < 20000 - 1)
	{
		instruction = cursor;
		while (a[instruction] == a[cursor] && cursor < 20000 - 1)
			cursor++;
		if ((a[instruction] == RA && a[cursor] == RRA)
			|| (a[instruction] == RRA && a[cursor] == RA))
		{
			a[instruction] = BLANK;
			a[cursor] = BLANK;
			optimization_result(2);
		}
		if ((a[instruction] == RB && a[cursor] == RRB)
			|| (a[instruction] == RRB && a[cursor] == RB))
		{
			a[instruction] = BLANK;
			a[cursor] = BLANK;
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
