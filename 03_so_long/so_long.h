/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:36:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/25 23:03:58 by vsyutkin         ###   ########.fr       */
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

# define DIR_RIGHT 0
# define DIR_DOWN 1
# define DIR_LEFT 2
# define DIR_UP 3

# define ERR_MAP_PATH "Error\nMap path is wrong\n"
# define ERR_MAP_OPEN "Error\nCouldn't open map file\n"
# define ERR_MAP_EXTENSION "Error\nMap file extension is not .ber\n"
# define ERR_MAP_CONTENT "Error\nMap content is invalid\n"
# define ERR_MAP_DEAD_END "Error\nMap is impossible to solve\n"

////////////////////////////////////////////////////////////////////////////////
				/* STRUCT */
////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////
					/* 02 */
////////////////////////////////////////////////////////////////////////////////

void	key_esc(mlx_key_data_t keydata, void *param);

////////////////////////////////////////////////////////////////////////////////
					/* 03 */
////////////////////////////////////////////////////////////////////////////////

	//	map_check.c

void	check_map(t_map *map_grid, t_allocs **allocs);
int		content_check(int c, t_map *map_grid);
int		grid_len(t_map *map_grid, t_allocs **allocs);
int		grid_height(t_map *map_grid, t_allocs **allocs);
void	inner_check(t_map *map_grid, t_allocs **allocs);

	//	map_check2.c

void	collectible_path_check(t_map *map_grid, t_allocs **allocs);
t_map	*goto_exit(t_map *map_grid);
void	make_path(t_map *start_cell);
void	path_check(t_map *map_grid, t_allocs **allocs);
void	outer_check(t_map *map_grid, t_allocs **allocs);

	//	map_grid.c

void	grid_fix(t_map **map, t_allocs **allocs);
void	horizontal_fix(t_map *cell_start);
t_map	*find_cell(t_map **map, int cell_x, int cell_y);
void	vertical_fix(t_map *cell_start);

	//	maps.c

void	check_map_extension(int argc, char **argv);
void	load_map(const char *line, t_map **map_grid, t_allocs **allocs);
void	map(int argc, char **argv, t_map **map_grid, t_allocs **allocs);
void	map_init(int content, int x, int y, t_map *map_cell);
void	read_map(char *map, t_map **map_grid, t_allocs **allocs);

////////////////////////////////////////////////////////////////////////////////
					/* 04 */
////////////////////////////////////////////////////////////////////////////////

void	ft_error(char *error, t_allocs **allocs);

#endif