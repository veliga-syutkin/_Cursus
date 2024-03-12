/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:00:39 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/12 20:57:19 by vsyutkin         ###   ########.fr       */
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
	// ft_printf("step_f = %d, step_b = %d\n", step_f, step_b);
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

static void	ft_ra(t_list **list)
{
	// ft_printf("list->data: %d; list->next->data: %d\n", (*list)->data, (*list)->next->data);
	// if ((*list)->data > (*list)->next->data)
	// 	sa(list);
	ra(list);
}

static void ft_rra(t_list **list)
{
	// ft_printf("list->data: %d; list->next->data: %d\n", (*list)->data, (*list)->next->data);
	if ((*list)->data > (*list)->next->data
		&& get_last_data(*list, 0) < (*list)->next->data)
		sa(list);
	rra(list);
}

static void ft_start(t_list **list_a, t_list **list_b)
{
	int		cursor;

	cursor = 0;
	while (cursor < 3)
	{
		pb(list_a, list_b);
		cursor++;
	}
	solve_3b(list_b);
	while (*list_b)
		pa(list_a, list_b);
}

void	solve(t_list *list_a, t_list *list_b)
{
	int		len;
	int		min;

	len = get_len(list_a);//, ft_printf("list len: %d\n", len);
	ft_start(&list_a, &list_b);
	while (get_len(list_a) > 3)
	{
		min = find_min(list_a);//, ft_printf("min in list A = %d\n", min);
		if (find_shortest(list_a))
			while (list_a->data != min)
				/*ft_printf("list_a->data: %d; ", list_a->data),*/ ft_ra(&list_a);//, ft_while(50000);
		else
			while (list_a->data != min)
				ft_rra(&list_a);
		pb(&list_a, &list_b);
	}
	solve_3(&list_a);
	while (list_b)
		pa(&list_a, &list_b);
}
