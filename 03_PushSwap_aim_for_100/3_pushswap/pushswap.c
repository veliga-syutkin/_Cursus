/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:09:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 03:21:37 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	methods(0, 0, 0);
	check(argc, argv, 2);
	list_a = setup(argc, argv);
	list_b = NULL;
	flag_method(WRITE, STDOUT);
	if (get_len(list_a) == 1 || sorted(list_a))
		return (clear_list(&list_a), 0);
	else if (get_len(list_a) == 2)
	{
		if (list_a->data > list_a->next->data)
			rra(&list_a);
	}
	else if (get_len(list_a) == 3)
		solve_3(&list_a);
	else
		run_solvers(&list_a, &list_b, argc, argv);
	return (clear_list(&list_a), 0);
}
