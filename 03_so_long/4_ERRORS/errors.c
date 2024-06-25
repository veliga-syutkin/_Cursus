/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:42:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 17:56:57 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
  Takes error message and prints it to the stdout,
  if needed, frees all allocated memory,
  exits the program with EXIT_FAILURE
*/
void	ft_error(char *error, t_allocs **allocs)
{
	mlx_t	*mlx;

	mlx = address_mlx(NULL);
	(void)ft_printf("%s\n", error);
	if (mlx)
		mlx_terminate(mlx);
	if (allocs && *allocs)
		mhandler_free_all(allocs);
	exit(EXIT_FAILURE);
}
