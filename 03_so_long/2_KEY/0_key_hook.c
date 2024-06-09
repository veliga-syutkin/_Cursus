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

void	ft_mlx_key_hook(mlx_key_data_t keydata, void *param)
{
	key_esc(keydata, param);
	key_up(keydata, param);
	key_down(keydata, param);
	key_left(keydata, param);
	key_right(keydata, param);
}
