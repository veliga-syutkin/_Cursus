/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stak_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:44:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/05 21:19:20 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stak_a(t_list **list_a)
{
	int	data;

	data = get_last_data(*list_a, 0);
	if ((*list_a)->data > (*list_a)->next->data && (*list_a)->data < data)
	{
		sx(list_a);
		ft_putstr_fd("sa\n", 1);
	}
}
