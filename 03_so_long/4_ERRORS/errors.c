/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:42:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/23 18:00:50 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *error, t_allocs **allocs)
{
	ft_printf("Error\n%s\n", error);
	if (*allocs && allocs)
		mhandler_free_all(allocs);
	exit(EXIT_FAILURE);
}
