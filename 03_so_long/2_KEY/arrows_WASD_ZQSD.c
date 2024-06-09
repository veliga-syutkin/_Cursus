/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-09 05:16:34 by vsyutkin          #+#    #+#             */
/*   Updated: 2024-06-09 05:16:34 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_up(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_Z && keydata.action == MLX_RELEASE))
	{
		ft_printf("Key pressed: UP\n");
		player(map, DIR_UP);
	}
}

void	key_down(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE))
	{
		ft_printf("Key pressed: DOWN\n");
		player(map, DIR_DOWN);
	}
}

void	key_left(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_Q && keydata.action == MLX_RELEASE))
	{
		ft_printf("Key pressed: LEFT\n");
		player(map, DIR_LEFT);
	}
}

void	key_right(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE))
	{
		ft_printf("Key pressed: RIGHT\n");
		player(map, DIR_RIGHT);
	}
}
