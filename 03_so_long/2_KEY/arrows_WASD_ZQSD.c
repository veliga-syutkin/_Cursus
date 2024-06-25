/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_WASD_ZQSD.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 05:16:34 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 20:45:42 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
  Function to make action when a directional key is pressed.
*/
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

/*
  Function to make action when a directional key is pressed.
*/
void	key_down(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE))
	{
		display_player(NULL, NULL, player(map, DIR_DOWN));
		counter_turns(player(map, 0));
	}
}

/*
  Function to make action when a directional key is pressed.
*/
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

/*
  Function to make action when a directional key is pressed.
*/
void	key_right(mlx_key_data_t keydata, void *map)
{
	if ((keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE) \
		|| (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE))
	{
		display_player(NULL, NULL, player(map, DIR_RIGHT));
		counter_turns(player(map, 0));
	}
}

/*
  Function that prints every move done by the player.
*/
void	counter_turns(t_map *new_pos)
{
	static t_map	*old_pos;
	char			dummy[2];

	dummy[0] = '\r';
	dummy[1] = '\0';
	if (old_pos != new_pos)
	{
		ft_printf("Turns: %i\n", turns(true));
		message(dummy);
	}
	old_pos = new_pos;
}
