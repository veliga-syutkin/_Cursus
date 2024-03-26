/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:07:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/26 16:06:49 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./0_LIBFT/libft.h"

# define YES 1
# define NO 0

# define BLANK (int)' '
# define SA (int)'A'
# define SB (int)'B'
# define SS (int)'C'
# define PA (int)'D'
# define PB (int)'E'
# define RA (int)'F'
# define RB (int)'G'
# define RR (int)'H'
# define RRA (int)'I'
# define RRB (int)'J'
# define RRR (int)'K'

# define WRITE 2
# define READ 1
# define END 0
# define OPTI 42

# define WEIGHT_RA 0
# define WEIGHT_RRA 1
# define WEIGHT_RB 2
# define WEIGHT_RRB 3

////////////////////////////////////////////////////////////////////////////////
				/* STRUCT */
////////////////////////////////////////////////////////////////////////////////


/*
weight[0] = ra
weight[1] = rra
weight[2] = rb
weight[3] = rrb
weight[4] = rr
weight[5] = rrr
weight[6] = default
*/
typedef struct s_list {
	struct s_list	*next;
	int				data;
	int				weight[7];
}	t_list;

////////////////////////////////////////////////////////////////////////////////
				/* 01 */
////////////////////////////////////////////////////////////////////////////////

void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
void	pax(t_list **list_a, t_list **list_b);
void	pbx(t_list **list_a, t_list **list_b);

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

void	rotate_string(int *str, int len);
void	reverse_rotate_string(int *str, int len);
int		*list_a_to_string(t_list **list_a, t_list **list_b);
int		*list_b_to_string(t_list **list_a, t_list **list_b);
void	order_string(int *data, int len);

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
bool	order(t_list *list);

t_list	*create(int *data, int len);
int		get_next_data(t_list *list, int data);
void	clear_list(t_list **list);

t_list	*setup(int argc, char **argv);
int		ft_atoi_prime(const char *nptr, int *cursor_nptr);

bool	find_shortest(t_list *stack);
void	index_sort(t_list *index);
void	solve(t_list **list_a, t_list **list_b);

void	solve_3(t_list **list);
void	solve_3b(t_list **list);
bool	sorted(t_list *list);
bool	reverse_sorted(t_list *list);

t_stack	**instruction(int flag);
void	ft_lstprint_and_free(t_stack **instructions);

////////////////////////////////////////////////////////////////////////////////
				/* 04 */
////////////////////////////////////////////////////////////////////////////////

void	add_instruction(int instruction);
void	print_instructions(int *a);
void	print_percentage(void);
int		*string_instruction(int move, int flag);

int		optimization_result(int flag);
void	print_instructions_t(int instruction);

#endif