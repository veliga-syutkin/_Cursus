/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:07:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/12 20:35:15 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./0_LIBFT/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

////////////////////////////////////////////////////////////////////////////////
				/* STRUCT */
////////////////////////////////////////////////////////////////////////////////

typedef struct s_list {
	struct s_list	*next;
	int				data;
}	t_list;

////////////////////////////////////////////////////////////////////////////////
				/* 01 */
////////////////////////////////////////////////////////////////////////////////

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);

void	ra(t_list **list);
void	rb(t_list **list);
void	rr(t_list **list_a, t_list **list_b);
void	rx(t_list **list);

void	rra(t_list **list);
void	rrb(t_list **list);
void	rrr(t_list **list_a, t_list **list_b);
void	rrx(t_list **list);

void	sa(t_list **list);
void	sb(t_list **list);
void	ss(t_list **list_a, t_list **list_b);
void	sx(t_list **list);

////////////////////////////////////////////////////////////////////////////////
				/* 02 */
////////////////////////////////////////////////////////////////////////////////

void	check(int argc, char **argv);
void	dquote(char **argv);
void	error(t_list **list);

////////////////////////////////////////////////////////////////////////////////
				/* 03 */
////////////////////////////////////////////////////////////////////////////////

int		find_max(t_list *list);
int		find_min(t_list *list);
int		get_len(t_list *list);
int		get_last_data(t_list *list, int offset);
void	reset_and_pb(t_list **list_a, t_list **list_b);

t_list	*create(int *data, int len);
int		get_next_data(t_list *list, int data);
void	clear_list(t_list **list);

t_list	*setup(int argc, char **argv);
int		ft_atoi_prime(const char *nptr, int *cursor_nptr);

bool	find_shortest(t_list *stack);
void	index_sort(t_list *index);
void	solve(t_list *list_a, t_list *list_b);

void	solve_3(t_list **list);
void	solve_3b(t_list **list);
bool	sorted(t_list *list);

#endif