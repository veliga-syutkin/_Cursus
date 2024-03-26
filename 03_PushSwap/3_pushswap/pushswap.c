/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:09:35 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/26 13:35:21 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	check(argc, argv);
	list_a = setup(argc, argv);
	list_b = NULL;
	if (get_len(list_a) == 1 || sorted(list_a))
		return (clear_list(&list_a), 0);
	string_instruction(0, END);
	if (get_len(list_a) == 2)
		if (list_a->data > list_a->next->data)
			rra(&list_a);
	if (get_len(list_a) == 3)
		solve_3(&list_a);
	else
		solve(&list_a, &list_b);
	print_instructions(string_instruction(0, OPTI));
	return (clear_list(&list_a), 0);
}
