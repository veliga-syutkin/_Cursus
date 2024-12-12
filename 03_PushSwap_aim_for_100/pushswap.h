/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:07:54 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/12 16:51:41 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./0_LIBFT/libft.h"

# define YES 1
# define NO 0

# define BLANK 32
# define SA 65
# define SB 66
# define SS 67
# define PA 68
# define PB 69
# define RA 70
# define RB 71
# define RR 72
# define RRA 73
# define RRB 74
# define RRR 75

# define WRITE 2
# define READ 1
# define END 0
# define OPTI 42

# define WEIGHT_RA 0
# define WEIGHT_RRA 1
# define WEIGHT_RB 2
# define WEIGHT_RRB 3
# define WEIGHT_RR 4
# define WEIGHT_RRR 5
# define WEIGHT_RARB 6
# define WEIGHT_RRARRB 7
# define WEIGHT_RARRB 8
# define WEIGHT_RRARB 9

////////////////////////////////////////////////////////////////////////////////
				/* STRUCT */
////////////////////////////////////////////////////////////////////////////////

/*
weight[0] = steps for ra
weight[1] = steps for rra
weight[2] = steps for rb
weight[3] = steps for rrb
weight[4] = steps for rr
weight[5] = steps for rrr
weight[6] = cost for ra and rb
weight[7] = cost for rra and rrb
weight[8] = cost for ra and rrb
weight[9] = cost for rra and rb
*/
typedef struct s_list
{
	struct s_list	*next;
	int				data;
	int				weight[10];
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

void	ft_start(t_list **list_a, t_list **list_b);
void	turk_move(t_list **list_a, t_list **list_b, int data);
void	weight_update_a(t_list **list_a, t_list **list_b);
int		data_min_weight(t_list **list);

void	ft_last_last_move(t_list **list_a, t_list **list_b);
void	ft_last_move(t_list **list_a, t_list **list_b);

int		ft_find_ra(t_list **list_a, int target);
int		ft_find_rb(t_list **list_b, int target);
int		ft_cost_rarb(int *weight);
int		ft_cost_rrarrb(int *weight);
void	ft_cost_default(int *weight);

void	ft_move_rarb(t_list **list_a, t_list **list_b, t_list *temp);
void	ft_move_rrarrb(t_list **list_a, t_list **list_b, t_list *temp);
void	ft_move_rarrb(t_list **list_a, t_list **list_b, t_list *temp);
void	ft_move_rrarb(t_list **list_a, t_list **list_b, t_list *temp);

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

int		ft_find_rx(int data, t_list *list);
int		ft_find_rrx(int data, t_list *list);
void	maxmin_ra_or_rra(t_list **list, int data);
void	maxmin_rb_or_rrb(t_list **list, int data);
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

////////////////////////////////////////////////////////////////////////////////
				/* ++ */
////////////////////////////////////////////////////////////////////////////////

void	weight_update_b(t_list **list_a, t_list **list_b);
void	turk_move_b(t_list **list_a, t_list **list_b, int data);
int		ft_find_r_single(int target, t_list *list);

#endif