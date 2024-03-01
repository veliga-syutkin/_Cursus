/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:20:12 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/03/01 01:03:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

// static
// int	ft_recursive_power(int nb, int power)
// {
// 	if (power == 0)
// 		return (1);
// 	if (power < 0)
// 		return (0);
// 	return (nb * ft_recursive_power(nb, power - 1));
// }

void	ft_while(int max)
{
	static int	count;
	static int	power;
	int			percent;
	static int	progress;

	percent = (max / 100);
	if (count == (percent * power))
	{
		ft_printf("%d%%\t[WHILE] in progress...\n", (progress));
		power++;
		progress++;
	}
	if (count == max)
	{
		ft_printf("\t[WHILE] looped (over %d loops), aborting.\n", max);
		exit(EXIT_FAILURE);
	}
	count++;
}
