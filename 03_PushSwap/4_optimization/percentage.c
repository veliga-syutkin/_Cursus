/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:44:37 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/23 22:15:37 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	print_percentage(void)
{
	static unsigned int	percentage;

	percentage++;
	if (percentage % 1 == 0)
		ft_printf("\t\t\t\t\t\tDone %d operations.\n", percentage);
}
