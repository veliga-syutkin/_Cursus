/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:53:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 18:04:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_window(void *param)
{
	mlx_close_window(param);
	ft_printf("Initiated window closing\n");
}

void	key_esc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		ft_printf("Key pressed: ESC\n");
		close_window(param);
	}
}
