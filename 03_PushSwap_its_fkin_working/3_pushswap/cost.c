/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:05:23 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/10 10:07:06 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_find_ra(int data, t_list *list_a)
{
	int		cost;
	t_list	*temp;

	cost = 0;
	temp = list_a;
	while (temp && temp->data != data)
	{
		temp = temp->next;
		cost++;
	}
	return (cost);
}

int	ft_find_rb(t_list **list_b, int target)
{
	t_list	*temp;
	int		cost_rx;

	cost_rx = 0;
	temp = *list_b;
	while ((temp) && (temp)->next)
	{
		if (target < find_min(*list_b) || target > find_max(*list_b))
		{
			cost_rx = ft_find_rx(find_max(*list_b), *list_b);
			break ;
		}
		cost_rx++;
		if ((temp)->data > target && target > (temp)->next->data)
			break ;
		(temp) = (temp)->next;
	}
	return (cost_rx);
}

/* COST RR
How many times we can rotate stack A and stack B simultaneously
Example:	ra = 5; rb = 10; rr = 5
*/
int	ft_cost_rarb(int *weight)
{
	int	ra;
	int	rb;

	ra = weight[WEIGHT_RA];
	rb = weight[WEIGHT_RB];
	if (ra >= rb)
		return (rb);
	return (ra);
}

/* COST RRR
How many times we can reverse rotate stack A and stack B simultaneously
Example:	rra = 10; rrb = 5; rrr = 5
*/
int	ft_cost_rrarrb(int *weight)
{
	int	rra;
	int	rrb;

	rra = weight[WEIGHT_RRA];
	rrb = weight[WEIGHT_RRB];
	if (rra >= rrb)
		return (rrb);
	return (rra);
}

void	ft_cost_default(int *weight)
{
	weight[WEIGHT_RARB] = weight[WEIGHT_RA]
		+ weight[WEIGHT_RB] - weight[WEIGHT_RR];
	weight[WEIGHT_RRARRB] = weight[WEIGHT_RRA]
		+ weight[WEIGHT_RRB] - weight[WEIGHT_RRR];
	weight[WEIGHT_RARRB] = weight[WEIGHT_RA] + weight[WEIGHT_RRB];
	weight[WEIGHT_RRARB] = weight[WEIGHT_RRA] + weight[WEIGHT_RB];
}
