/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:33:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2023/12/04 14:11:01 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack visualization
void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	while (tmp)
	{
		ft_printf("%d, value: %d\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
}

// current tests
int	main(int argc, char **argv)
{
	t_stack	*test;
	int		cursor;

	if (argc >= 2)
	{
		test = ft_lstnew(ft_atoi(argv[1]));
	}
	if (argc >= 3)
	{
		cursor = 2;
		while (argv[cursor])
		{
			ft_lstadd_back(&test, ft_lstnew(ft_atoi(argv[cursor])));
			cursor++;
		}
	}
	ft_print_stack(test);
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
