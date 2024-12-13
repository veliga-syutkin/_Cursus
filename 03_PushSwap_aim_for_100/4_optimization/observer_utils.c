/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:50 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/13 13:55:52 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static
void	print_step(t_allocs *method)
{
	if (ft_strncmp(method->content, SA, 1) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(method->content, SB, 1) == 0)
		write(1, "sb\n", 3);
	else if (ft_strncmp(method->content, SS, 1) == 0)
		write(1, "ss\n", 3);
	else if (ft_strncmp(method->content, PA, 1) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(method->content, PB, 1) == 0)
		write(1, "pb\n", 3);
	else if (ft_strncmp(method->content, RA, 1) == 0)
		write(1, "ra\n", 3);
	else if (ft_strncmp(method->content, RB, 1) == 0)
		write(1, "rb\n", 3);
	else if (ft_strncmp(method->content, RR, 1) == 0)
		write(1, "rr\n", 3);
	else if (ft_strncmp(method->content, RRA, 1) == 0)
		write(1, "rra\n", 4);
	else if (ft_strncmp(method->content, RRB, 1) == 0)
		write(1, "rrb\n", 4);
	else if (ft_strncmp(method->content, RRR, 1) == 0)
		write(1, "rrr\n", 4);
}

void	print_method(t_allocs *method)
{
	while (method)
	{
		print_step(method);
		method = method->next;
	}
}

int	count_steps(t_allocs *method)
{
	int		count;

	count = 0;
	while (method)
	{
		count++;
		method = method->next;
	}
	return (count);
}

/* Wich method is currently in use.
+ flag_rw = WRITE or READ
+ method = METHOD_50, METHOD_66, METHOD_75, METHOD_99
*/
int	flag_method(int flag_rw, int method)
{
	static int	flag;

	if (flag_rw == WRITE)
		flag = method;
	return (flag);
}

void	method_free(t_allocs *m50, t_allocs *m66, t_allocs *m75, t_allocs *m99)
{
	mhandler_free_all(&m50);
	mhandler_free_all(&m66);
	mhandler_free_all(&m75);
	mhandler_free_all(&m99);
}
