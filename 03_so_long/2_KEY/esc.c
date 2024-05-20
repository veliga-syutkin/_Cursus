/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:53:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/20 23:31:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	close_window(void *param)
{
	ft_printf("Key pressed: ESC\n");
	mlx_close_window(param);
	ft_printf("Initiated window closing\n");
}

void	key_esc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		close_window(param);
	}
}
