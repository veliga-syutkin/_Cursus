/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

static
void	ft_getsign(const char *c, int *sign, int *cursor, int *cursor_nptr)
{
	if (*c == '+')
		*sign = 1;
	else if (*c == '-')
		*sign = -1;
	else
		*sign = 0;
	*cursor = *cursor + 1;
	*cursor_nptr = *cursor_nptr + 1;
	return ;
}

static
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, int *cursor_nptr)
{
	int	cursor;
	int	sign;
	int	result;

	cursor = 0;
	result = 0;
	if (!ft_isdigit(*(nptr + cursor)))
		ft_getsign(nptr + cursor, &sign, &cursor, cursor_nptr);
	else if (ft_isdigit(*(nptr + cursor)))
		sign = 1;
	while (*(nptr + cursor) == '0')
	{
		cursor++;
		*cursor_nptr = *cursor_nptr + 1;
	}
	while (ft_isdigit(*(nptr + cursor)))
	{
		result = (result * 10) + *((char *)nptr + cursor++) - '0';
		*cursor_nptr = *cursor_nptr + 1;
	}
	if (!cursor)
		*cursor_nptr = *cursor_nptr + 1;
	return (result * sign);
}

long int	ft_atoi_long(const char *nptr, int *cursor_nptr)
{
	int			cursor;
	int			sign;
	long int	result;

	cursor = 0;
	result = 0;
	if (!ft_isdigit(*(nptr + cursor)))
		ft_getsign(nptr + cursor, &sign, &cursor, cursor_nptr);
	else if (ft_isdigit(*(nptr + cursor)))
		sign = 1;
	while (*(nptr + cursor) == '0')
		cursor++;
	while (ft_isdigit(*(nptr + cursor)))
		result = (result * 10) + *((char *)nptr + cursor++) - '0';
	return (result * sign);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	char_allowed_sign(char **c, int cursor_c, int cursor_v)
{
	char	*buffer;

	buffer = *(c + cursor_c) + cursor_v;
	if (*buffer == '-' || *buffer == '+')
	{
		if (*(buffer + 1) == '-' || *(buffer + 1) == '+')
			error();
		if (cursor_v)
			if (*(buffer - 1) != ' ')
				error();
		return (1);
	}
	return (0);
}

static
int	char_allowed(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static
void	check_max(char *number)
{
	int	useless;

	useless = 0;
	if (ft_atoi_long(number, &useless) > 2147483647)
		error();
}

static
void	check_number(int argc, char **argv)
{
	int	csr_argc;

	csr_argc = 1;
	while (csr_argc < argc)
	{
		if (ft_strlen(*(argv + csr_argc++)) > 10)
			error();
		if (ft_strlen(*(argv + csr_argc - 1)) == 10)
			check_max(*(argv + csr_argc - 1));
	}
}

void	check(int argc, char **argv)
{
	int		csr_argc;
	int		csr_argv;

	csr_argc = 1;
	csr_argv = 0;
	while (csr_argc < argc)
	{
		if (!*(*(argv + csr_argc) + csr_argv))
		{
			csr_argv = 0;
			csr_argc++;
		}
		else if (char_allowed(*(*(argv + csr_argc) + csr_argv)))
			csr_argv++;
		else if (char_allowed_sign(argv, csr_argc, csr_argv))
			csr_argv++;
		else
			error();
	}
	if (argc == 1)
		exit(0);
	check_number(argc, argv);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_reset_rrb(t_list *list)
{
	int	cost;

	while (list->next && list->data > list->next->data)
		list = list->next;
	if (!list->next)
		return (0);
	cost = 0;
	while (list->next)
	{
		list = list->next;
		cost++;
	}
	return (cost);
}

int	cost_to_reset_rb(t_list *list)
{
	int	cost;

	cost = 0;
	while (list->next && list->data > list->next->data)
	{
		list = list->next;
		cost++;
	}
	if (!list->next)
		return (0);
	return (cost);
}

int	find_cost_rb(t_list *element, t_list *list_b)
{
	int	first;
	int	last;
	int	cost;

	if (element->data > find_max(list_b) || element->data < find_min(list_b))
	{
		if (cost_to_reset_rb(list_b) < cost_to_reset_rrb(list_b))
			return (cost_to_reset_rb(list_b));
		return (cost_to_reset_rrb(list_b));
	}
	cost = 0;
	first = list_b->data;
	last = get_last_data(list_b, 0);
	while (element->data < first || element->data > last)
	{
		last = first;
		first = get_next_data(list_b, first);
		cost++;
	}
	return (cost);
}

int	find_cost_rrb(t_list *element, t_list *list_b)
{
	int	first;
	int	last;
	int	cost;

	if (element->data > find_max(list_b) || element->data < find_min(list_b))
	{
		if (cost_to_reset_rb(list_b) < cost_to_reset_rrb(list_b))
			return (cost_to_reset_rb(list_b));
		return (cost_to_reset_rrb(list_b));
	}
	cost = 0;
	first = list_b->data;
	last = get_last_data(list_b, 0);
	while (element->data < first || element->data > last)
	{
		first = last;
		last = get_last_data(list_b, ++cost);
	}
	return (cost);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	intchr(int *data, int sample, int len)
{
	int	occurence;
	int	cursor;

	cursor = 0;
	occurence = 0;
	while (cursor < len)
		if (*(cursor++ + data) == sample)
			occurence++;
	if (occurence != 1)
		return (1);
	return (0);
}

static
void	check_duplicate(int *data, int len)
{
	int	cursor;

	cursor = 0;
	while (cursor < len)
	{
		if (intchr(data, *(data + cursor++), len))
		{
			free(data);
			error();
		}
	}
}

t_list	*create(int *data, int len)
{
	int		cursor;
	t_list	*result;
	t_list	*buffer;

	check_duplicate(data, len);
	cursor = 0;
	result = malloc(sizeof(t_list));
	if (!result)
		error();
	buffer = result;
	buffer->data = *data;
	cursor++;
	while (cursor < len)
	{
		buffer->next = malloc(sizeof(t_list));
		buffer = buffer->next;
		if (!buffer)
			error();
		buffer->data = *(data + cursor);
		cursor++;
	}
	buffer->next = NULL;
	return (result);
}

int	get_next_data(t_list *list, int data)
{
	while (list->data != data)
		list = list->next;
	return (list->next->data);
}

void	clear_list(t_list **list)
{
	t_list	*buffer;
	t_list	*buffer_next;

	buffer = *list;
	while (buffer->next)
	{
		buffer_next = buffer->next;
		free(buffer);
		buffer = buffer_next;
	}
	free(buffer);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *list)
{
	int	max;

	max = list->data;
	while (list)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

int	find_min(t_list *list)
{
	int	min;

	min = list->data;
	while (list)
	{
		if (list->data < min)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	get_len(t_list *list)
{
	int	len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

int	get_last_data(t_list *list, int offset)
{
	int	cursor;
	int	len;

	cursor = 1;
	len = get_len(list);
	while (list->next && cursor < len - offset)
	{
		list = list->next;
		cursor++;
	}
	return (list->data);
}

void	reset_and_pb(t_list **list_a, t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rx(list_b);
		write(1, "rb\n", 3);
	}
	pb(list_a, list_b);
	write(1, "pb\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *list)
{
	while (list->next && list->data < list->next->data)
		list = list->next;
	list = list->next;
	if (!list)
		return (1);
	return (0);
}

void	make_left_rra(t_list **list_a, int left_rra)
{
	if (get_len(*list_a) == 3 || get_len(*list_a) == 2)
		return ;
	while (left_rra)
	{
		rrx(list_a);
		write(1, "rra\n", 4);
		left_rra--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		left_rra;

	check(argc, argv);
	list_a = setup(argc, argv);
	list_b = NULL;
	left_rra = 0;
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
	if (get_len(list_a) > 3)
		left_rra = solve(&list_a, &list_b);
	make_left_rra(&list_a, left_rra);
	clear_list(&list_a);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_b)
	{
		buffer = (*list_b)->next;
		(*list_b)->next = (*list_a);
		(*list_a) = (*list_b);
		(*list_b) = buffer;
	}
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;

	if (*list_a)
	{
		buffer = (*list_a)->next;
		(*list_a)->next = (*list_b);
		(*list_b) = (*list_a);
		(*list_a) = buffer;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>

# include "../ft_printf/ft_printf.h"

typedef struct s_list {
	struct s_list	*next;
	int				data;
}	t_list;

//function in error.c

void		error(void);

//function in check.c

void		check(int argc, char **argv);

//function in setup.c

t_list		*setup(int argc, char **argv);

//function in list.c

t_list		*create(int *data, int len);
int			get_next_data(t_list *list, int data);
void		clear_list(t_list **list);

//function in list_utils.c

int			find_max(t_list *list);
int			find_min(t_list *list);
int			get_len(t_list *list);
int			get_last_data(t_list *list, int offset);
void		reset_and_pb(t_list **list_a, t_list **list_b);

//function in ft_atoi.c

int			ft_atoi(const char *nptr, int *cursor_nptr);
long int	ft_atoi_long(const char *nptr, int *cursor_nptr);

//function in swap.c

void		ss(t_list **list_a, t_list **list_b);
void		sx(t_list **list);

//function in push.c

void		pa(t_list **list_a, t_list **list_b);
void		pb(t_list **list_a, t_list **list_b);

//function in rotate.c

void		rr(t_list **list_a, t_list **list_b);
void		rx(t_list **list);
void		rrr(t_list **list_a, t_list **list_b);
void		rrx(t_list **list);

//function in solve.c

int			solve(t_list **list_a, t_list **list_b);

//function in solve_3.c

void		solve_3(t_list **list);

//function in find_cost.c

int			cost_to_reset_rb(t_list *list);
int			cost_to_reset_rrb(t_list *list);
int			find_cost_rb(t_list *element, t_list *list_b);
int			find_cost_rrb(t_list *element, t_list *list_b);

//function in reset.c

void		reset_rb(t_list **list);
void		reset_rrb(t_list **list);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_rb(t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rx(list_b);
		write(1, "rb\n", 3);
	}
}

void	reset_rrb(t_list **list_b)
{
	while ((*list_b)->data < get_last_data(*list_b, 0))
	{
		rrx(list_b);
		write(1, "rrb\n", 4);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **list_a, t_list **list_b)
{
	rx(list_a);
	rx(list_b);
}

void	rx(t_list **list)
{
	t_list	*buffer;

	buffer = (*list);
	if (!buffer || !buffer->next)
		return ;
	while (buffer->next)
		buffer = buffer->next;
	buffer->next = (*list);
	(*list) = (*list)->next;
	buffer->next->next = NULL;
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rrx(list_a);
	rrx(list_b);
}

void	rrx(t_list **list)
{
	t_list	*buffer;

	buffer = (*list);
	if (!buffer || !buffer->next)
		return ;
	while (buffer->next->next)
		buffer = buffer->next;
	buffer->next->next = (*list);
	(*list) = buffer->next;
	buffer->next = NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	*extend(int *buffer, int buffer_len, int value)
{
	int	*result;
	int	cursor;

	if (!buffer)
	{
		result = malloc(sizeof(int));
		if (!result)
			error();
		*result = value;
		return (result);
	}
	result = malloc((buffer_len + 1) * sizeof(int));
	if (!result)
	{
		free(buffer);
		error();
	}
	cursor = -1;
	while (cursor++ < buffer_len - 1)
		*(result + cursor) = *(buffer + cursor);
	*(result + cursor) = value;
	return (free(buffer), result);
}

t_list	*setup(int argc, char **argv)
{
	int		*buffer;
	int		buffer_len;
	int		csr_argc;
	int		csr_argv;
	t_list	*result;

	buffer = NULL;
	buffer_len = 0;
	csr_argc = 1;
	csr_argv = 0;
	while (csr_argc < argc)
	{
		if (!*(*(argv + csr_argc) + csr_argv))
		{
			csr_argv = 0;
			csr_argc++;
		}
		else if (*(*(argv + csr_argc) + csr_argv) != ' ')
			buffer = extend(buffer, buffer_len++, \
			ft_atoi(*(argv + csr_argc) + csr_argv, &csr_argv));
		else
			csr_argv++;
	}
	result = create(buffer, buffer_len);
	return (free(buffer), result);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	list_state(t_list *list)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = list->data;
	nb2 = list->next->data;
	nb3 = list->next->next->data;
	if (nb3 > nb1 && nb1 > nb2)
		return (213);
	else if (nb1 > nb2 && nb2 > nb3)
		return (321);
	else if (nb1 > nb3 && nb3 > nb2)
		return (312);
	else if (nb2 > nb3 && nb3 > nb1)
		return (132);
	else if (nb2 > nb1 && nb1 > nb3)
		return (231);
	return (123);
}

void	solve_3(t_list **list)
{
	int		state;

	state = list_state(*list);
	if (state == 132 || state == 321 || state == 213)
	{
		sx(list);
		write(1, "sa\n", 3);
	}
	if (state == 312 || state == 132)
	{
		rx(list);
		write(1, "ra\n", 3);
	}
	if (state == 231 || state == 321)
	{
		rrx(list);
		write(1, "rra\n", 4);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	find_cheapest(t_list **list_a, t_list **list_b)
{
	t_list	*buffer;
	int		cheapest;
	int		cheapest_cost;
	int		rotate_cost;

	buffer = (*list_a);
	cheapest = (*list_a)->data;
	cheapest_cost = find_cost_rb(*list_a, *list_b);
	rotate_cost = 0;
	while (buffer && rotate_cost < cheapest_cost)
	{
		if (find_cost_rb(buffer, *list_b) + rotate_cost < cheapest_cost)
		{
			cheapest_cost = find_cost_rb(buffer, *list_b) + rotate_cost - 1;
			cheapest = buffer->data;
		}
		if (find_cost_rrb(buffer, *list_b) + rotate_cost++ < cheapest_cost)
		{
			cheapest_cost = find_cost_rrb(buffer, *list_b) + rotate_cost - 1;
			cheapest = buffer->data;
		}
		buffer = buffer->next;
	}
	return (cheapest);
}

static
void	chose_move(t_list **list_a, t_list **list_b)
{
	int	first;
	int	last;

	first = (*list_b)->data;
	last = get_last_data(*list_b, 0);
	if (find_cost_rb(*list_a, *list_b) <= find_cost_rrb(*list_a, *list_b))
	{
		while ((*list_a)->data < first || (*list_a)->data > last)
		{
			rx(list_b);
			write(1, "rb\n", 3);
			first = (*list_b)->data;
			last = get_last_data(*list_b, 0);
		}
		return ;
	}
	while ((*list_a)->data < first || (*list_a)->data > last)
	{
		rrx(list_b);
		write(1, "rrb\n", 4);
		first = (*list_b)->data;
		last = get_last_data(*list_b, 0);
	}
}

static
void	do_cheapest(t_list **list_a, t_list **list_b)
{
	int	cheapest;

	cheapest = find_cheapest(list_a, list_b);
	while ((*list_a)->data != cheapest)
	{
		rx(list_a);
		write(1, "ra\n", 3);
	}
	if ((*list_a)->data > find_max(*list_b))
		return (reset_and_pb(list_a, list_b));
	if ((*list_a)->data < find_min(*list_b))
		return (reset_and_pb(list_a, list_b));
	chose_move(list_a, list_b);
	pb(list_a, list_b);
	write(1, "pb\n", 3);
}

static
void	check_rra(t_list **list_a, t_list **list_b, int *moved)
{
	if (get_last_data(*list_a, 0) > (*list_b)->data && *moved < 3)
	{
		rrx(list_a);
		write(1, "rra\n", 4);
		*moved = *moved + 1;
	}
	else
	{
		pa(list_a, list_b);
		write(1, "pa\n", 3);
	}
}

int	solve(t_list **list_a, t_list **list_b)
{
	int	moved;

	moved = 0;
	pb(list_a, list_b);
	write(1, "pb\n", 3);
	if (get_len(*list_a) > 4)
	{
		pb(list_a, list_b);
		write(1, "pb\n", 3);
	}
	while ((*list_a)->next->next && (*list_a)->next->next->next)
		do_cheapest(list_a, list_b);
	if (cost_to_reset_rb(*list_b) < cost_to_reset_rrb(*list_b))
		reset_rb(list_b);
	else
		reset_rrb(list_b);
	solve_3(list_a);
	while (*list_b)
		check_rra(list_a, list_b, &moved);
	return (3 - moved);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **list_a, t_list **list_b)
{
	sx(list_a);
	sx(list_b);
}

void	sx(t_list **list)
{
	t_list	*buffer;

	if (list && *list && (*list)->next)
	{
		buffer = (*list)->next;
		(*list)->next = (*list)->next->next;
		buffer->next = (*list);
		(*list) = buffer;
	}
}
