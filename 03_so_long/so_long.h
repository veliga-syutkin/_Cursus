/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:36:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/23 22:05:07 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./0_LIBFT/libft.h"
# include "./1_MLX42/include/MLX42/MLX42.h"
# include "./9_MHANDLER/mhandler.h"

# define WIDTH 1024
# define HEIGHT 1024
# define WALL '1'
# define EXIT 'E'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'

# define TOP_LEFT (int *)-1
# define SOMEWHERE (int *)-2

# define ERR_MAP_PATH "Error\nMap path is wrong\n"
# define ERR_MAP_OPEN "Error\nCouldn't open map file\n"
# define ERR_MAP_EXTENSION "Error\nMap file extension is not .ber\n"
# define ERR_MAP_CONTENT "Error\nMap content is invalid\n"

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
	struct s_map	*down;
	struct s_map	*left;
	struct s_map	*right;
	int				content;
	int				xy[2];
	bool			path_check;
}	t_map;

void	ft_error(char *error, t_allocs **allocs);

void	key_esc(mlx_key_data_t keydata, void *param);

void	map(int argc, char **argv, t_map **map_grid, t_allocs **allocs);
void	check_map_extension(int argc, char **argv);
void	load_map(const char *line, t_map **map_grid, t_allocs **allocs);
void	read_map(char *map, t_map **map_grid, t_allocs **allocs);

#endif