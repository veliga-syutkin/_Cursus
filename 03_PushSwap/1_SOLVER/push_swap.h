/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:44:18 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/01/05 11:11:02 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../0_LIBFT/libft.h"
# include <stdlib.h>

typedef struct s_list {
	struct s_list	*next;
	int				data;
}	t_list;

//error.c

void		error(t_list **list);

//	* * * 
// #############################################################################

//check.c

void		check(int argc, char **argv);

//	* * * 
// #############################################################################


//dquote.c

void	dquote(char **argv);

//	* * * 
// #############################################################################

//setup.c

t_list		*setup(int argc, char **argv);

//	* * * 
// #############################################################################

//list.c

t_list		*create(int *data, int len);
int			get_next_data(t_list *list, int data);
void		clear_list(t_list **list);

//	* * *
// #############################################################################

//list_utils.c

int			find_max(t_list *list);
int			find_min(t_list *list);
int			get_len(t_list *list);
int			get_last_data(t_list *list, int offset);
void		reset_and_pb(t_list **list_a, t_list **list_b);

//	* * * 
// #############################################################################

//ft_atoi.c

int			ft_atoi(const char *nptr, int *cursor_nptr);
long int	ft_atoi_long(const char *nptr, int *cursor_nptr);

//	* * * 
// #############################################################################

//swap.c

void		ss(t_list **list_a, t_list **list_b);
void		sx(t_list **list);

//	* * * 
// #############################################################################

//push.c

void		pa(t_list **list_a, t_list **list_b);
void		pb(t_list **list_a, t_list **list_b);

//	* * * 
// #############################################################################

//rotate.c

void		rr(t_list **list_a, t_list **list_b);
void		rx(t_list **list);
void		rrr(t_list **list_a, t_list **list_b);
void		rrx(t_list **list);

//	* * * 
// #############################################################################

//solve.c

int			solve(t_list **list_a, t_list **list_b);

//	* * * 
// #############################################################################

//solve_3.c

void		solve_3(t_list **list);

//	* * * 
// #############################################################################

//find_cost.c

int			cost_to_reset_rb(t_list *list);
int			cost_to_reset_rrb(t_list *list);
int			find_cost_rb(t_list *element, t_list *list_b);
int			find_cost_rrb(t_list *element, t_list *list_b);

//	* * * 
// #############################################################################

//reset.c

void		reset_rb(t_list **list);
void		reset_rrb(t_list **list);

//	* * * 
// #############################################################################

#endif