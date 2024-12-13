/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:59:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/13 15:12:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*	observer2.0*/

/*
	Have at least 2 variants of turk: 
	- turk with threshold get_len(list_a) > get_len(list_b) (50% sorted)
	- turk with threshold get_len(list_a) * 2 > get_len(list_b) (66% sorted)
	- turk with threshold get_len(list_a) * 3 - 1 > get_len(list_b) (75% sorted)
	- turk with threshold get_len(list_a) > 3 (99% sorted)

	Each variation stocks each step in chained list (incorporate mhandler to ps)

	Each variation would be compared to each other at the end. 
	The best variation would be chosen and printed out.
	(comparing lenght of chained list)
*/

/*
	[DEPRECATED]
		The observer works reccursively (?). 
		It takes as parameters 2 lists and chained list of steps.
		The observer will store the state of the list when called,
			then will compare both lists at each further step 
			(effectively stocking 2 states of 2 lists: 
			both lists at the start and both lists at the end).
		If the lists will be same at any moment, 
			the observer returns how many steps further this happens.
		If the lists do not become same, the observer will return 0.
		When the observer returns 0, the step is marked as approuved 
			and observer is restarted from the next step.
		When the observer returns a number, 
			nexts [returned number] steps should be whipped,
			and observer is restarted from next (non whipped) step.

*/

/*
FLAG_RW:
	- READ: observer is reading the list
	- WRITE: observer is writing to the list

METHOD_TO:
	- METHOD_50: 50% sorted
	- METHOD_66: 66% sorted
	- METHOD_75: 75% sorted
	- METHOD_99: 99% sorted
	- free all methods

OPERATOR:
SS, SA, SB, PA, PB, RA, RB, RR, RRA, RRB, RRR
*/
t_allocs	*methods(int flag_rw, int method_to, void *operator)
{
	static t_allocs	*method50;
	static t_allocs	*method66;
	static t_allocs	*method75;
	static t_allocs	*method99;

	if (flag_rw == WRITE)
	{
		if (method_to == METHOD_50)
			mhandler_check(&method50, operator, &methods);
		else if (method_to == METHOD_66)
			mhandler_check(&method66, operator, &methods);
		else if (method_to == METHOD_75)
			mhandler_check(&method75, operator, &methods);
		else if (method_to == METHOD_99)
			mhandler_check(&method99, operator, &methods);
	}
	if (method_to == METHOD_50)
		return (method50);
	else if (method_to == METHOD_66)
		return (method66);
	else if (method_to == METHOD_75)
		return (method75);
	else if (method_to == METHOD_99)
		return (method99);
	return (method_free(method50, method66, method75, method99), NULL);
}

t_allocs	*best_m(t_allocs *m50, t_allocs *m66, t_allocs *m75, t_allocs *m99)
{
	int		len50;
	int		len66;
	int		len75;
	int		len99;

	len50 = count_steps(m50);
	len66 = count_steps(m66);
	len75 = count_steps(m75);
	len99 = count_steps(m99);
	if (len50 <= len66 && len50 <= len75 && len50 <= len99)
		return (m50);
	else if (len66 <= len50 && len66 <= len75 && len66 <= len99)
		return (m66);
	else if (len75 <= len50 && len75 <= len66 && len75 <= len99)
		return (m75);
	else
		return (m99);
}

void	print_best_method(void)
{
	t_allocs	*m50;
	t_allocs	*m66;
	t_allocs	*m75;
	t_allocs	*m99;
	t_allocs	*best;

	m50 = methods(READ, METHOD_50, 0);
	m66 = methods(READ, METHOD_66, 0);
	m75 = methods(READ, METHOD_75, 0);
	m99 = methods(READ, METHOD_99, 0);
	best = best_m(m50, m66, m75, m99);
	print_method(best);
	method_free(m50, m66, m75, m99);
}
