/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:53:36 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/20 22:37:05 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_esc(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		ft_printf("Key pressed: ESC\n");
		exit(0);
	}
}