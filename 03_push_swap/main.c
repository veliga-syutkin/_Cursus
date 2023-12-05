/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:33:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/05 14:22:46 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
}

void	ft_tests(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_print_stacks(stack_a, stack_b);
	rotate(stack_a);
	push(stack_a, stack_b);
	reverses(stack_a, stack_b);
}

// current stack_a
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		cursor;

	if (argc >= 2)
	{
		stack_a = ft_lstnew(ft_atoi(argv[1]));
	}
	else if (argc >= 3)
	{
		cursor = 2;
		while (argv[cursor])
		{
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[cursor])));
			cursor++;
		}
	}
	else
	{
		stack_a = NULL;
	}
	stack_b = NULL;
	pos_end(&stack_a);
	ft_print_stack(stack_a);
	ft_tests(stack_a, stack_b);
	ft_lstclear(stack_a, free);
	return (0);
}


// Final form
// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	if (argc < 2)
// 		return (0);
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (argc == 2)
// 		stack_a = ft_read_from_string(argv[1]);
// 	else
// 		stack_a = ft_read_from_argv(argc, argv);
// 	if (ft_check_stack(stack_a) == 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return (0);
// 	}
// 	ft_sort(&stack_a, &stack_b);
// 	ft_free_stack(&stack_a);
// 	ft_free_stack(&stack_b);
// 	return (0);
// }
