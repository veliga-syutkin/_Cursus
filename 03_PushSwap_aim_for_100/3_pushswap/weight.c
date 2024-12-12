/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:11:26 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/12 16:54:12 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// LOOK TO NOT USE IT ANYMORE
// makes B with 3 elements sorted
// void	ft_start(t_list **list_a, t_list **list_b)
// {
// 	int		cursor;

// 	cursor = 0;
// 	if ((*list_a)
// 		&& (*list_a)->next
// 		&& (*list_a)->next->next
// 		&& (*list_a)->next->next->next
// 		&& (*list_a)->data > (*list_a)->next->data
// 		&& (*list_a)->next->next->data < (*list_a)->next->next->next->data)
// 	{
// 		pbx(list_a, list_b);
// 		pbx(list_a, list_b);
// 		ss(list_a, list_b);
// 		pbx(list_a, list_b);
// 	}
// 	else
// 	{
// 		while (cursor < 3)
// 		{
// 			pbx(list_a, list_b);
// 			cursor++;
// 		}
// 		solve_3b(list_b);
// 	}
// }

// Compares what element in A is cheapest to move to good position in B
// as long the way to move it (either rr/ra/rb, rrr/rra/rrb, ra/rrb or rra/rb)
void	turk_move(t_list **list_a, t_list **list_b, int data)
{
	t_list	*temp;
	int		rrarrb;
	int		rarrb;
	int		rrarb;

	temp = *list_a;
	while (temp->data != data && temp->next)
		temp = temp->next;
	rrarrb = temp->weight[WEIGHT_RRARRB];
	rarrb = temp->weight[WEIGHT_RARRB];
	rrarb = temp->weight[WEIGHT_RRARB];
	if (temp->weight[WEIGHT_RARB] < rrarrb && temp->weight[WEIGHT_RARB] < rarrb
		&& temp->weight[WEIGHT_RARB] < rrarb)
		ft_move_rarb(list_a, list_b, temp);
	else if (rrarrb < rarrb && rrarrb < rrarb)
		ft_move_rrarrb(list_a, list_b, temp);
	else if (rarrb < rrarb)
		ft_move_rarrb(list_a, list_b, temp);
	else
		ft_move_rrarb(list_a, list_b, temp);
}

// Compares what element in B is cheapest to move to good position in A
// as long the way to move it (either rr/ra/rb, rrr/rra/rrb, ra/rrb or rra/rb)
void	turk_move_b(t_list **list_a, t_list **list_b, int data)
{
	t_list	*temp;
	int		rrarrb;
	int		rarrb;
	int		rrarb;

	temp = *list_b;
	while (temp->data != data && temp->next)
		temp = temp->next;
	rrarrb = temp->weight[WEIGHT_RRARRB];
	rarrb = temp->weight[WEIGHT_RARRB];
	rrarb = temp->weight[WEIGHT_RRARB];
	if (temp->weight[WEIGHT_RARB] < rrarrb && temp->weight[WEIGHT_RARB] < rarrb
		&& temp->weight[WEIGHT_RARB] < rrarb)
		ft_move_rarb(list_a, list_b, temp);
	else if (rrarrb < rarrb && rrarrb < rrarb)
		ft_move_rrarrb(list_a, list_b, temp);
	else if (rarrb < rrarb)
		ft_move_rarrb(list_a, list_b, temp);
	else
		ft_move_rrarb(list_a, list_b, temp);
}

// Updates the weight (= operations cost) of each element in A
void	weight_update_a(t_list **list_a, t_list **list_b)
{
	int		data;
	t_list	*temp;

	temp = *list_a;
	while (temp)
	{
		data = (temp)->data;
		(temp)->weight[0] = ft_find_rx(data, *list_a);
		(temp)->weight[1] = get_len(*list_a) - (temp)->weight[0];
		(temp)->weight[2] = ft_find_rb(list_b, data);
		(temp)->weight[3] = get_len(*list_b) - (temp)->weight[2];
		(temp)->weight[4] = ft_cost_rarb((temp)->weight);
		(temp)->weight[5] = ft_cost_rrarrb((temp)->weight);
		ft_cost_default((temp)->weight);
		(temp) = (temp)->next;
	}
}
/*	temp = *list_a;
	while (temp)
	{
		ft_printf("data: %d; ra: %d; rra: %d; rb: %d; rrb: %d; rr: %d; rrr: %d;\
	RA-RB: %d; RRA-RRB: %d; RA-RRB: %d; RRA-RB: %d\n",
			temp->data, temp->weight[0], temp->weight[1], temp->weight[2],\
	temp->weight[3], temp->weight[4], temp->weight[5], temp->weight[6], \
	temp->weight[7], temp->weight[8], temp->weight[9]);
		temp = temp->next;
	}*/

// Updates the weight (= operations cost) of each element in B
void	weight_update_b(t_list **list_a, t_list **list_b)
{
	int		data;
	t_list	*temp;

	temp = *list_b;
	while (temp)
	{
		data = (temp)->data;
		(temp)->weight[0] = ft_find_ra(list_a, data);
		(temp)->weight[1] = get_len(*list_a) - (temp)->weight[0];
		(temp)->weight[2] = ft_find_rx(data, *list_b);
		(temp)->weight[3] = get_len(*list_b) - (temp)->weight[2];
		(temp)->weight[4] = ft_cost_rarb((temp)->weight);
		(temp)->weight[5] = ft_cost_rrarrb((temp)->weight);
		ft_cost_default((temp)->weight);
		(temp) = (temp)->next;
	}
}
/*	temp = *list_b;
	while (temp)
	{
		ft_printf("data: %d; ra: %d; rra: %d; rb: %d; rrb: %d; rr: %d; rrr: %d;\
	RA-RB: %d; RRA-RRB: %d; RA-RRB: %d; RRA-RB: %d\n",
			temp->data, temp->weight[0], temp->weight[1], temp->weight[2],\
	temp->weight[3], temp->weight[4], temp->weight[5], temp->weight[6], \
	temp->weight[7], temp->weight[8], temp->weight[9]);
		temp = temp->next;
	}*/

// returns wich data has the less weight
int	data_min_weight(t_list **list)
{
	t_list	*temp;
	t_list	*min;
	int		cost;

	temp = *list;
	min = temp;
	cost = INT_MAX;
	while (temp && temp->next && cost != 0)
	{
		if (cost > temp->weight[6] || cost > temp->weight[7]
			|| cost > temp->weight[8] || cost > temp->weight[9])
		{
			min = temp;
			if (temp->weight[6] < cost)
				cost = temp->weight[6];
			if (temp->weight[7] < cost)
				cost = temp->weight[7];
			if (temp->weight[8] < cost)
				cost = temp->weight[8];
			if (temp->weight[9] < cost)
				cost = temp->weight[9];
		}
		temp = temp->next;
	}
	return (min->data);
}
/*	ft_printf("\t\tData with min weight: %d \t with actual cost of: %d\n",\
	min->data, cost);*/
