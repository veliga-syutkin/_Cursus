/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_key_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-09 05:29:04 by vsyutkin          #+#    #+#             */
/*   Updated: 2024-06-09 05:29:04 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	MLX key hook implementation for following keys:
ESCAPE
ARROWS (UP, DOWN, RIGHT, LEFT)
WASD (english keyboard)
ZQSD (french keyboard)
*/
void	ft_mlx_key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map_grid;
	mlx_t	*mlx;

	(void)param;
	mlx = address_mlx(NULL);
	map_grid = address_map(NULL);
	key_esc(keydata, mlx);
	key_up(keydata, map_grid);
	key_down(keydata, map_grid);
	key_left(keydata, map_grid);
	key_right(keydata, map_grid);
}
