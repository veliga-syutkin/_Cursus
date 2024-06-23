/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_WASD_ZQSD.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 05:16:34 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/23 16:56:21 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_up(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_Z && keydata.action == MLX_RELEASE))
	{
		display_player(NULL, NULL, player(map, DIR_UP));
		counter_turns(player(map, 0));
	}
}

void	key_down(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE))
	{
		display_player(NULL, NULL, player(map, DIR_DOWN));
		counter_turns(player(map, 0));
	}
}

void	key_left(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_Q && keydata.action == MLX_RELEASE))
	{
		display_player(NULL, NULL, player(map, DIR_LEFT));
		counter_turns(player(map, 0));
	}
}

void	key_right(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE))
	{
		display_player(NULL, NULL, player(map, DIR_RIGHT));
		counter_turns(player(map, 0));
	}
}

void	counter_turns(t_map *new_pos)
{
	static t_map	*old_pos;

	if (old_pos != new_pos)
		ft_printf("Turns: %i\n", turns(true));
	old_pos = new_pos;
}
