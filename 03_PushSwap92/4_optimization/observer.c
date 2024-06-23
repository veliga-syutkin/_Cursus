/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:59:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/22 15:10:11 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*

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