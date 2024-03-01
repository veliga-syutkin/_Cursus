/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:00:39 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/01 02:32:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

bool	find_shortest(t_list *stack)
{
	t_list	*temp;
	int		step_f;
	int		step_b;
	int		min;

	step_f = 0;
	step_b = 0;
	min = find_min(stack);
	temp = stack;
	while (temp->data != min)
	{
		temp = temp->next;
		step_f++;
	}
	while (temp->next)
	{
		temp = temp->next;
		step_b++;
	}
	ft_printf("step_f = %d, step_b = %d\n", step_f, step_b);
	if (step_f <= step_b)
		return (true);
	return (false);
}

void	index_sort(t_list *index)
{
	t_list	*temp;
	int		data_temp;

	temp = index;
	while (index && index->next)
	{
		if (index->data > index->next->data)
		{
			data_temp = index->data;
			index->data = index->next->data;
			index->next->data = data_temp;
			index = temp;
		}
		else
			index = index->next;
	}
}

void	solve(t_list *list_a, t_list *list_b, int argc, char **argv)
{
	 t_list	*temp;
	int		len;
	int		cursor;
	int		min;

	if (!argc && !argv)
		return ;
	cursor = 0;
	min = find_min(list_a);
	temp = list_a;
	len = get_len(list_a);
	ft_printf("checkpoint 1\n");
	while (temp)
	{
		if (find_shortest(temp))
			while (temp->data != min)
				ra(&list_a), ft_while(50000);
		else
			while (temp->data != min)
				rra(&list_a);
		pb(&list_a, &list_b);
	}
	// while (list_b)
	// 	pa(&list_a, &list_b);
}
