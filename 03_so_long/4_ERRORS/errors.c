/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:42:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/21 03:51:28 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack)->content);
		free(stack);
		*stack = temp;
	}
}

void	ft_error(char *error, t_stack *stack)
{
	ft_printf("Error\n%s\n", error);
	if (stack)
		ft_free(stack);
	exit(1);
}
