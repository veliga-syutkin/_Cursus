/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:36:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/21 00:15:41 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./0_LIBFT/libft.h"
# include "./1_MLX42/include/MLX42/MLX42.h"

# define WIDTH 1024
# define HEIGHT 1024
# define WALL '1'
# define EXIT 'E'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'

void	key_esc(mlx_key_data_t keydata, void *param);

/*
Map structure
->top = cell on top
->bottom = cell on bottom
->left = cell on left
->right = cell on right
->content = what is in the cell
->xy = unique coordinates of the cell. xy[0] = x, xy[1] = y
->path_check = if the cell is reachable FROM EXIT.
*/
typedef struct s_map
{
	struct s_map	*top;
	struct s_map	*bottom;
	struct s_map	*left;
	struct s_map	*right;
	int				content;
	int				xy[2];
	bool			path_check;
}	t_map;

#endif