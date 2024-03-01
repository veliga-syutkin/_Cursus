/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:09:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/01 02:18:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	check(argc, argv);
	ft_printf("Input is correct\n"); //comment
	list_a = setup(argc, argv);
	list_b = NULL;
	ft_printf("Succesfully initialized\n");
	if (get_len(list_a) == 1 || sorted(list_a))
		return (clear_list(&list_a), 0);
	if (get_len(list_a) == 2)
	{
		if (list_a->data > list_a->next->data)
		{
			rrx(&list_a);
			write(1, "rra\n", 4);
		}
	}
	if (get_len(list_a) == 3)
		solve_3(&list_a);
	solve(list_a, list_b, argc, argv); // Here is the main function that will solve the task
	// check the rightness of the input
	// do the sorting and checking the sorting
	// print the result
	return (clear_list(&list_a), 0);
}