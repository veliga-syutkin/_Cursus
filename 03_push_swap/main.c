/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:33:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/11/27 03:40:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		stack_a = ft_read_from_string(argv[1]);
	else
		stack_a = ft_read_from_argv(argc, argv);
	if (ft_check_stack(stack_a) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
