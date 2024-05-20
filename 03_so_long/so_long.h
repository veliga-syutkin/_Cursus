/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:36:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/20 22:24:35 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./0_LIBFT/libft.h"
# include "./1_MLX42/include/MLX42/MLX42.h"

# define WIDTH 1024
# define HEIGHT 1024

void	key_esc(mlx_key_data_t keydata, void *param);

#endif