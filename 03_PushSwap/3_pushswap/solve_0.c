/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:00:39 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/24 05:16:50 by vsyutkin         ###   ########.fr       */
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

// static void	ft_ra(t_list **list)
// {
// 	// ft_printf("list->data: %d; list->next->data: %d\n", (*list)->data, (*list)->next->data);
// 	// if ((*list)->data > (*list)->next->data)
// 	// 	sa(list);
// 	ra(list);
// }

// static void ft_rra(t_list **list)
// {
// 	// ft_printf("list->data: %d; list->next->data: %d\n", (*list)->data, (*list)->next->data);
// 	if ((*list)->data > (*list)->next->data
// 		&& get_last_data(*list, 0) < (*list)->next->data)
// 		sa(list);
// 	rra(list);
// }

// static void ft_index_sort(int len, int *data)
// {
// 	int	cursor;
// 	int	temp;

// 	cursor = 0;
// 	while (cursor < len)
// 	{
// 		if (cursor < len - 1 && data[cursor] > data[cursor + 1])
// 		{
// 			temp = data[cursor];
// 			data[cursor] = data[cursor + 1];
// 			data[cursor + 1] = temp;
// 		}
// 		cursor++;
// 	}
// }

// static void ft_index_list(t_list *list, const int *data, int len)
// {
// 	int		cursor;

// 	cursor = 0;
// 	while (list)
// 	{
// 		while ((list)->data != data[cursor] && cursor < len)
// 			cursor++;
// 		(list)->index = cursor;
// 		cursor = 0;
// 		list = (list)->next;
// 	}
// }

// static void ft_index(t_list *list)
// {
// 	int		len;
// 	int		*data;
// 	int		cursor;
// 	t_list	*temp;

// 	temp = list;
// 	cursor = 0;
// 	len = get_len(list);
// 	data = (int *)malloc(sizeof(int) * len);
// 	if (!data)
// 		error(&list);
// 	while (cursor < len)
// 	{
// 		data[cursor] = (list)->data;
// 		list = (list)->next;
// 		cursor++;
// 	}
// 	list = temp;
// 	ft_index_sort(len, data);
// 	ft_index_list(list, data, len);
// 	free(data);
// }

static void ft_start(t_list **list_a, t_list **list_b)
{
	int		cursor;

	cursor = 0;
	// ft_index(*list_a);
	if ((*list_a)
		&& (*list_a)->next
		&& (*list_a)->next->next
		&& (*list_a)->next->next->next
		&& (*list_a)->data > (*list_a)->next->data
		&& (*list_a)->next->next->data < (*list_a)->next->next->next->data
			// && !(get_last_data(*list_b, 0) > (*list_a)->data && (*list_a)->data > (*list_b)->data)
			)
		{
			pbx(list_a, list_b);
			pbx(list_a, list_b);
			ss(list_a, list_b);
		}
	else
	{	while (cursor < 3)
		{
			pbx(list_a, list_b);
			cursor++;
		}
		solve_3b(list_b);
	}
}

////////////////////////////////////////////////////////////////////////////////

int	ft_find_rx(int data, t_list *list)
{
	int		cost_rx;
	int		cost_rrx;
	int		len;
	t_list	*last;

	len = get_len(list);
	last = list;
	while (last && last->next)
		last = last->next;
	cost_rx = 0;
	cost_rrx = 0;
	while (list)
	{
		if (data == list->data)
			break ;
		list = list->next;
		cost_rx++;
	}
	while (list)
	{
		list = list->next;
		cost_rrx++;
	}
	return (cost_rx);
}

int	ft_find_rrx(int data, t_list *list)
{
	int		cost_rx;
	int		cost_rrx;
	int		len;
	t_list	*last;

	len = get_len(list);
	last = list;
	while (last && last->next)
		last = last->next;
	cost_rx = 0;
	cost_rrx = 0;
	while (list)
	{
		if (data == list->data)
			break ;
		list = list->next;
		cost_rx++;
	}
	while (list)
	{
		list = list->next;
		cost_rrx++;
	}
	return (cost_rrx);
}

static void maxmin_ra_or_rra(t_list **list, int data)
{
	int	cost_rx;
	int	cost_rrx;

	cost_rx = ft_find_rx(data, *list);
	cost_rrx = ft_find_rrx(data, *list);
	if (cost_rx <= cost_rrx)
		while (cost_rx--)
			ra(list);
	else
		while (cost_rrx--)
			rra(list);
}

static void maxmin_rb_or_rrb(t_list **list, int data)
{
	int	cost_rx;
	int	cost_rrx;

	cost_rx = ft_find_rx(data, *list);
	cost_rrx = ft_find_rrx(data, *list);
	if (cost_rx <= cost_rrx)
		while (cost_rx--)
			rb(list);
	else
		while (cost_rrx--)
			rrb(list);
}

// rb ou rrb
static void ft_next_next_move(t_list **list_a, t_list **list_b)
{
	int		cost_rx;
	int		cost_rrx;
	int		*data;

	cost_rx = 0;
	cost_rrx = 0;
	data = list_b_to_string(list_a, list_b);
	while (!((*list_a)->data > data[0] && (*list_a)->data < data[get_len(*list_b) - 1]))
	{
		rotate_string(data, get_len(*list_b));
		cost_rx++;
	}
	free(data);
	cost_rrx = get_len(*list_b) - cost_rx;
	if (cost_rx <= cost_rrx)
		while (cost_rx)
			rb(list_b), cost_rx--;
	else
		while (cost_rrx)
			rrb(list_b), cost_rrx--;
}

// ra ou rra
static void ft_last_last_move(t_list **list_a, t_list **list_b)
{
	int		cost_rx;
	int		cost_rrx;
	int		*data;

	cost_rx = 0;
	cost_rrx = 0;
	data = list_a_to_string(list_a, list_b);
	while (!((data[get_len(*list_a) - 1] < (*list_b)->data
		&& (*list_b)->data < data[0])
		|| (data[get_len(*list_a) - 1] > data[0]
		&& data[get_len(*list_a) - 1] > (*list_b)->data
		&& data[0] > (*list_b)->data)))
	{
		rotate_string(data, get_len(*list_a));
		cost_rx++;
	}
	free(data);
	cost_rrx = get_len(*list_a) - cost_rx;
	if (cost_rx <= cost_rrx)
		while (cost_rx)
			ra(list_a), cost_rx--;
	else
		while (cost_rrx)
			rra(list_a), cost_rrx--;
}

static void	ft_pb_pb_ss(t_list **list_a, t_list **list_b)
{
	if ((*list_a)
		&& (*list_a)->next
		&& (*list_a)->next->next
		&& (*list_a)->next->next->next)
	{
		if ((*list_a)->data > (*list_a)->next->data
			&& (*list_a)->next->data > (*list_a)->next->next->data
			&& (*list_a)->next->next->data > (*list_a)->next->next->next->data
			)
		{
			pbx(list_a, list_b);
			pbx(list_a, list_b);
			ss(list_a, list_b);
			pax(list_a, list_b);
			pax(list_a, list_b);
		}
	}
}

bool	ft_two_four_three(t_list **list_a)
{
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;

	one = get_last_data(*list_a, 1);
	two = get_last_data(*list_a, 0);
	three = (*list_a)->next->data;
	four = (*list_a)->data;
	five = (*list_a)->next->next->data;
	// ft_printf("one: %d; two: %d; three: %d; four: %d; five: %d\n", one, two, three, four, five);
	if (one < two && two < three && three < four && four < five)
		return (true);
	return (false);
}

bool	ft_three_two_four(t_list **list_a)
{
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;

	one = get_last_data(*list_a, 0);
	two = (*list_a)->next->data;
	three = (*list_a)->data;
	four = (*list_a)->next->next->data;
	five = (*list_a)->next->next->next->data;
	// ft_printf("one: %d; two: %d; three: %d; four: %d; five: %d\n", one, two, three, four, five);
	if (one < two && two < three && three < four && four < five)
		return (true);
	return (false);
}

bool	ft_three_four_two(t_list **list_a)
{
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;

	one = get_last_data(*list_a, 0);
	two = (*list_a)->next->next->data;
	three = (*list_a)->data;
	four = (*list_a)->next->data;
	five = (*list_a)->next->next->next->data;
	// ft_printf("one: %d; two: %d; three: %d; four: %d; five: %d\n", one, two, three, four, five);
	if (one < two && two < three && three < four && four < five)
		return (true);
	return (false);
}

bool	ft_four_two_three(t_list **list_a)
{
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;

	one = get_last_data(*list_a, 0);
	two = (*list_a)->next->data;
	three = (*list_a)->next->next->data;
	four = (*list_a)->data;
	five = (*list_a)->next->next->next->data;
	// ft_printf("one: %d; two: %d; three: %d; four: %d; five: %d\n", one, two, three, four, five);
	if (one < two && two < three && three < four && four < five)
		return (true);
	return (false);
}

bool	ft_four_three_two(t_list **list_a)
{
	int	one;
	int	two;
	int	three;
	int	four;
	int	five;

	one = get_last_data(*list_a, 0);
	two = (*list_a)->next->next->data;
	three = (*list_a)->next->data;
	four = (*list_a)->data;
	five = (*list_a)->next->next->next->data;
	// ft_printf("one: %d; two: %d; three: %d; four: %d; five: %d\n", one, two, three, four, five);
	if (one < two && two < three && three < four && four < five)
		return (true);
	return (false);
}

void	ft_sort_five(t_list **list_a, t_list **list_b)
{
	if (ft_two_four_three(list_a) || ft_three_two_four(list_a))
		sa(list_a);
	if (ft_three_four_two(list_a))
	{
		pbx(list_a, list_b);
		sa(list_a);
		pax(list_a, list_b);
	}
	if (ft_four_two_three(list_a))
	{
		pbx(list_a, list_b);
		ra(list_a);
		ra(list_a);
		pax(list_a, list_b);
	}
	if (ft_four_three_two(list_a))
	{
		pbx(list_a, list_b);
		sa(list_a);
		ra(list_a);
		ra(list_a);
		pax(list_a, list_b);
	}
}

bool	thousand_hundred_ten_one(t_list **list_a)
{
	int	one;
	int	ten;
	int	hundred;
	int	thousand;

	thousand = (*list_a)->data;
	hundred = (*list_a)->next->data;
	ten = (*list_a)->next->next->data;
	one = (*list_a)->next->next->next->data;
	if (one < ten && ten < hundred && hundred < thousand)
		return (true);
	return (false);
}

void	ft_sort_four(t_list **list_a, t_list **list_b)
{
	if (thousand_hundred_ten_one(list_a))
	{
		pbx(list_a, list_b);
		pbx(list_a, list_b);
		ss(list_a, list_b);
		ra(list_a);
		ra(list_a);
		pax(list_a, list_b);
		pax(list_a, list_b);
	}
}

/*
	[ DEBUG ] all while around this scope should become if for this to work.
*/
void	ft_sort_cases(t_list **list_a, t_list **list_b)
{
	ft_pb_pb_ss(list_a, list_b);
	if (list_a && (*list_a) && (*list_a)->next && (*list_a)->next->next
		&& (*list_a)->next->next->next)
	{
		ft_sort_five(list_a, list_b);
		ft_sort_four(list_a, list_b);
	}
}

void	max_or_min_ra_or_rra(t_list **list)
{
	int	cost_rx;
	int	cost_rrx;
	int	data;
	int	cost;

	data = find_min(*list);
	cost_rx = ft_find_rx(data, *list);
	cost_rrx = ft_find_rrx(data, *list);
	if (cost_rx <= cost_rrx)
		cost = cost_rx;
	else
		cost = cost_rrx;
	data = find_max(*list);
	cost_rx = ft_find_rx(data, *list);
	cost_rrx = ft_find_rrx(data, *list);
	if (cost < cost_rx && cost < cost_rrx)
		maxmin_ra_or_rra(list, find_min(*list));
	else
		maxmin_ra_or_rra(list, find_max(*list));
}

//	works as follows: 
/* 	Starts when list b is as long or longer than list a.
	Put on top of list b shortest. 
	find the NEXT to top element of list_b in list_a within range of last element of list_b. 
	RA or RRA. 
	PB. 
	If no more possible, rrb. 
*/	
static void ft_next_last_move(t_list **list_a, t_list **list_b)
{
	if ((*list_a)->data == find_min(*list_a))
		pbx(list_a, list_b);
	if ((*list_a)->data == find_max(*list_a))
	{
		pbx(list_a, list_b);
		rb(list_b);
	}
	else
		max_or_min_ra_or_rra(list_a);
}

/* take top element of stack a
 * find the shortest way to put it in stack b keeping stack b in order
 * put it in stack b
*/
static void ft_next_move(t_list **list_a, t_list **list_b)
{
	if (get_last_data(*list_b, 0) > (*list_a)->data && (*list_a)->data > (*list_b)->data)
		pbx(list_a, list_b);
	else if (get_last_data(*list_a, 0) == find_min(*list_a))
		rra(list_a);
	else if ((*list_a)->data < find_min(*list_b))
	{
		while ((*list_b)->data != find_min(*list_b))
			maxmin_rb_or_rrb(list_b, find_min(*list_b));
		rb(list_b);
		pbx(list_a, list_b);
	}
	else if ((*list_a)->data > find_max(*list_b))
	{
		while ((*list_b)->data != find_max(*list_b))
			maxmin_rb_or_rrb(list_b, find_max(*list_b));
		pbx(list_a, list_b);
	}
	else
		ft_next_next_move(list_a, list_b);
}

static void	ft_last_move(t_list **list_a, t_list **list_b)
{
	if ((get_last_data(*list_a, 0) < (*list_b)->data
		&& (*list_b)->data < (*list_a)->data)
		|| (get_last_data(*list_a, 0) > (*list_a)->data
		&& get_last_data(*list_a, 0) > (*list_b)->data
		&& (*list_a)->data > (*list_b)->data))
		pax(list_a, list_b);
	else if ((*list_b)->data > find_max(*list_a))
	{
			pax(list_a, list_b);
	}
	else
		ft_last_last_move(list_a, list_b);
}

void	solve(t_list **list_a, t_list **list_b)
{
	int		len;

	len = get_len(*list_a);
	ft_start(list_a, list_b);
	while (!(order((*list_a)) || get_len(*list_a) < get_len(*list_b)))
	{
		ft_sort_cases(list_a, list_b);
		// while (get_last_data(*list_a, 0) < (*list_a)->data)
		// 	rra(list_a);
		ft_next_move(list_a, list_b);
	}
	if ((*list_b)->data != find_max(*list_b))
		maxmin_rb_or_rrb(list_b, find_max(*list_b));
	while (get_len(*list_a) > 2)
	{
		ft_next_last_move(list_a, list_b);
	}
	maxmin_rb_or_rrb(list_b, find_max(*list_b));
	maxmin_ra_or_rra(list_a, find_min(*list_a));
	while (*list_b)
		ft_last_move(list_a, list_b);
	while ((*list_a)->data != find_min(*list_a))
		maxmin_ra_or_rra(list_a, find_min(*list_a));
}
