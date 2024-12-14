/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 02:48:44 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/14 15:26:13 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	execute_util(t_list **list_a, t_list **list_b, int flag)
{
	if (flag == 1)
	{
		sx(list_a);
		sx(list_b);
	}
	else if (flag == 2)
	{
		rx(list_a);
		rx(list_b);
	}
	else if (flag == 3)
	{
		rrx(list_a);
		rrx(list_b);
	}
}

/* Applies given moves to the stacks.
*/
void	execute(t_list **list_a, t_list **list_b, t_allocs *alc)
{
	if (!ft_strncmp((alc)->content, "rra\n", 4))
		rrx(list_a);
	else if (!ft_strncmp((alc)->content, "rrb\n", 4))
		rrx(list_b);
	else if (!ft_strncmp((alc)->content, "rrr\n", 4))
		execute_util(list_a, list_b, 3);
	else if (!ft_strncmp((alc)->content, "sa\n", 3))
		sx(list_a);
	else if (!ft_strncmp((alc)->content, "sb\n", 3))
		sx(list_b);
	else if (!ft_strncmp((alc)->content, "pa\n", 3))
		pa(list_a, list_b);
	else if (!ft_strncmp((alc)->content, "pb\n", 3))
		pb(list_a, list_b);
	else if (!ft_strncmp((alc)->content, "ra\n", 3))
		rx(list_a);
	else if (!ft_strncmp((alc)->content, "rb\n", 3))
		rx(list_b);
	else if (!ft_strncmp((alc)->content, "rr\n", 3))
		execute_util(list_a, list_b, 2);
	else if (!ft_strncmp((alc)->content, "ss\n", 3))
		execute_util(list_a, list_b, 1);
}

/* Checks that all provided steps are valid moves.
returns: true if all steps are valid, false otherwise.
*/
bool	check_steps(t_allocs **alc)
{
	t_allocs	*temp;

	if (!alc || !*alc)
		return (false);
	temp = *alc;
	while (temp)
	{
		if (!ft_strncmp(temp->content, "sa\n", 3)
			|| !ft_strncmp(temp->content, "sb\n", 3)
			|| !ft_strncmp(temp->content, "ss\n", 3)
			|| !ft_strncmp(temp->content, "rra\n", 4)
			|| !ft_strncmp(temp->content, "rrb\n", 4)
			|| !ft_strncmp(temp->content, "rrr\n", 4)
			|| !ft_strncmp(temp->content, "pa\n", 3)
			|| !ft_strncmp(temp->content, "pb\n", 3)
			|| !ft_strncmp(temp->content, "ra\n", 3)
			|| !ft_strncmp(temp->content, "rb\n", 3)
			|| !ft_strncmp(temp->content, "rr\n", 3))
			temp = temp->next;
		else
			return (false);
	}
	return (true);
}

bool	simuli(t_list **list_a, t_list **list_b, t_allocs **alc)
{
	t_allocs	*temp;

	if (!check_steps(alc))
		return (true);
	if (alc)
		temp = (*alc);
	else
		temp = NULL;
	while (temp)
	{
		execute(list_a, list_b, temp);
		temp = temp->next;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_allocs	*alc;
	char		*read;
	t_list		*list_a;
	t_list		*list_b;

	alc = NULL;
	check(argc, argv, 2);
	list_a = setup(argc, argv, 2);
	list_b = NULL;
	read = get_next_line(1);
	while (read)
	{
		mhandler_check(&alc, read, NULL);
		read = get_next_line(1);
	}
	if (simuli(&list_a, &list_b, &alc))
		ft_putendl_fd("Error", 2);
	else if (sorted(list_a) && !list_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	mhandler_free_all(&alc);
	clear_list(&list_a);
	return (EXIT_SUCCESS);
}
