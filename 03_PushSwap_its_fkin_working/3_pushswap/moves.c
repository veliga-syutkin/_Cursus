/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:03:30 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/04/15 12:48:24 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/* executes rr, ra and then rb */
void	ft_move_rarb(t_list **list_a, t_list **list_b, t_list *temp)
{
	t_list	*copy;

	copy = temp;
	while (copy->weight[WEIGHT_RR]-- > 0)
	{
		rr(list_a, list_b);
		copy->weight[WEIGHT_RA]--;
		copy->weight[WEIGHT_RB]--;
	}
	while (copy->weight[WEIGHT_RA]-- > 0)
		ra(list_a);
	while (copy->weight[WEIGHT_RB]-- > 0)
		rb(list_b);
}

/* executes rrr, rra and then rrb */
void	ft_move_rrarrb(t_list **list_a, t_list **list_b, t_list *temp)
{
	t_list	*copy;

	copy = temp;
	while (copy->weight[WEIGHT_RRR]-- > 0)
	{
		rrr(list_a, list_b);
		copy->weight[WEIGHT_RRA]--;
		copy->weight[WEIGHT_RRB]--;
	}
	while (copy->weight[WEIGHT_RRA]-- > 0)
		rra(list_a);
	while (copy->weight[WEIGHT_RRB]-- > 0)
		rrb(list_b);
}

// executes ra and then rrb
void	ft_move_rarrb(t_list **list_a, t_list **list_b, t_list *temp)
{
	t_list	*copy;

	copy = temp;
	while (copy->weight[WEIGHT_RA]-- > 0)
		ra(list_a);
	while (copy->weight[WEIGHT_RRB]-- > 0)
		rrb(list_b);
}

// executes rra and then rb
void	ft_move_rrarb(t_list **list_a, t_list **list_b, t_list *temp)
{
	t_list	*copy;

	copy = temp;
	while (copy->weight[WEIGHT_RRA]-- > 0)
		rra(list_a);
	while (copy->weight[WEIGHT_RB]-- > 0)
		rb(list_b);
}
