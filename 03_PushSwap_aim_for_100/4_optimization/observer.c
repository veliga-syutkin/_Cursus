/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:59:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/12/12 18:45:50 by vsyutkin         ###   ########.fr       */
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
method[0] = 50 or METHOD_50;
method[1] = 66 or METHOD_66;
method[2] = 75 or METHOD_75;
method[3] = 99 or METHOD_99;

*/
int	*methods(int flag_rw, int method_to, int operator)
{
	t_allocs	*method50;
	t_allocs	*method66;
	t_allocs	*method75;
	t_allocs	*method99;

	if (flag_rw == WRITE)
	{
		method50 = mhandler_add(&method50, operator, &methods);
		method66 = mhandler_add(&method66, operator, &methods);
		method75 = mhandler_add(&method75, operator, &methods);
		method99 = mhandler_add(&method99, operator, &methods);
	}
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
