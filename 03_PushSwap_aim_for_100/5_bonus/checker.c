/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 02:48:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 03:47:02 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	execute_util(t_list **list_a, t_list **list_b, int flag)
{
	if (flag == SS[0])
	{
		sx(list_a);
		sx(list_b);
	}
	else if (flag == RR[0])
	{
		rx(list_a);
		rx(list_b);
	}
	else if (flag == RRR[0])
	{
		rrx(list_a);
		rrx(list_b);
	}
}

/* Applies given moves to the stacks.
*/
void	execute(t_list **list_a, t_list **list_b, t_allocs **alc)
{
	while (alc && *alc)
	{
		if (!ft_strncmp((*alc)->content, "sa\n", 1))
			sx(list_a);
		else if (!ft_strncmp((*alc)->content, "sb\n", 3))
			sx(list_b);
		else if (!ft_strncmp((*alc)->content, "ss\n", 3))
			execute_util(list_a, list_b, SS[0]);
		else if (!ft_strncmp((*alc)->content, "pa\n", 3))
			pa(list_a, list_b);
		else if (!ft_strncmp((*alc)->content, "pb\n", 3))
			pb(list_a, list_b);
		else if (!ft_strncmp((*alc)->content, "ra\n", 3))
			rx(list_a);
		else if (!ft_strncmp((*alc)->content, "rb\n", 3))
			rx(list_b);
		else if (!ft_strncmp((*alc)->content, "rr\n", 3))
			execute_util(list_a, list_b, RR[0]);
		else if (!ft_strncmp((*alc)->content, "rra\n", 4))
			rrx(list_a);
		else if (!ft_strncmp((*alc)->content, "rrb\n", 4))
			rrx(list_b);
		execute_util(list_a, list_b, RRR[0]);
		*alc = (*alc)->next;
	}
}

/* Checks that all provided steps are valid moves.
returns: true if all steps are valid, false otherwise.
*/
bool	check_steps(t_allocs **alc)
{
	while (alc && *alc)
	{
		if (ft_strncmp((*alc)->content, "sa\n", 1)
			&& ft_strncmp((*alc)->content, "sb\n", 3)
			&& ft_strncmp((*alc)->content, "ss\n", 3)
			&& ft_strncmp((*alc)->content, "pa\n", 3)
			&& ft_strncmp((*alc)->content, "pb\n", 3)
			&& ft_strncmp((*alc)->content, "ra\n", 3)
			&& ft_strncmp((*alc)->content, "rb\n", 3)
			&& ft_strncmp((*alc)->content, "rr\n", 3)
			&& ft_strncmp((*alc)->content, "rra\n", 4)
			&& ft_strncmp((*alc)->content, "rrb\n", 4)
			&& ft_strncmp((*alc)->content, "rrr\n", 4))
			return (false);
		*alc = (*alc)->next;
	}
	return (true);
}

void	simuli(t_list **list_a, t_list **list_b, t_allocs **alc)
{
	if (!check_steps(alc))
	{
		ft_putstr_fd("Error\n", 1);
		return ;
	}
	execute(list_a, list_b, alc);
	if (sorted(*list_a) && !*list_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_allocs	*alc;
	char		*read;
	t_list		*list_a;
	t_list		*list_b;

	check(argc, argv, 1);
	list_a = setup(argc, argv, 1);
	list_b = NULL;
	read = get_next_line(1);
	while (read)
		mhandler_check(&alc, read, &main);
	simuli(&list_a, &list_b, &alc);
	mhandler_free_all(&alc);
	return (EXIT_SUCCESS);
}
