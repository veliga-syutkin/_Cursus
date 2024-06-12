/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:36:41 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/28 15:59:37 by vsyutkin         ###   ########.fr       */
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

// hating norminette right down here:
// # define TOP_LEFT (int *)-1
// # define SOMEWHERE (int *)-2

# define DIR_DOWN 1
# define DIR_LEFT 2
# define DIR_UP 3
# define DIR_RIGHT 4

# define ERR_MAP_PATH "Error\nDirectory path to map is wrong\n"
# define ERR_MAP_OPEN "Error\nCouldn't open map file\n"
# define ERR_MAP_EXTENSION "Error\nMap file extension is not .ber\n"
# define ERR_MAP_CONTENT "Error\nMap is corrupted\n"
# define ERR_MAP_DEAD_END "Error\nMap is impossible to solve\n"

# define MSG_WON "\tCONGRATULATION!\n\tYou WON!\nPress ESC to close the game.\n"
# define MSG_EXIT_CLOSED "You have to collect all collectibles!\n"

////////////////////////////////////////////////////////////////////////////////
				/* STRUCT */
////////////////////////////////////////////////////////////////////////////////

/*
Map structure
->top = cell on top
// ->down = cell on bottom/down
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

	//	0_key_hooks.c

void	ft_mlx_key_hook(mlx_key_data_t keydata, void *param);

	//	esc.c

void	key_esc(mlx_key_data_t keydata, void *param);
void	close_window(void *param);

	//	arrows_WASD_ZQSD.c

void	key_up(mlx_key_data_t keydata, void *map);
void	key_down(mlx_key_data_t keydata, void *map);
void	key_left(mlx_key_data_t keydata, void *map);
void	key_right(mlx_key_data_t keydata, void *map);

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
t_map	*goto_item(t_map *map_grid, int item);
void	make_path(t_map *start_cell);
void	path_check(t_map *map_grid, t_allocs **allocs);
void	outer_check(t_map *map_grid, t_allocs **allocs);

	//	map_grid.c

void	grid_fix(t_map **map, t_allocs **allocs);
void	horizontal_fix(t_map *cell_start);
t_map	*find_cell(t_map **map, int cell_x, int cell_y);
void	vertical_fix(t_map *cell_start);
void	print_map(t_map **map);

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

////////////////////////////////////////////////////////////////////////////////
					/* 05 */
////////////////////////////////////////////////////////////////////////////////

	//	collectible.c

bool	all_collected(void);
int		collectible(t_map *map);

	//	exit.c

bool	exit_game(t_map *map);

	//	messages.c

void	message(char *s);
void	notification(t_map *map);

////////////////////////////////////////////////////////////////////////////////
					/* 06 */
////////////////////////////////////////////////////////////////////////////////

	//	player.c

t_map	*player(t_map *map, int dir);
int		last_dir(int dir);
int		turns(bool count);

////////////////////////////////////////////////////////////////////////////////
					/* SO_LONG */
////////////////////////////////////////////////////////////////////////////////

	//	so_long.c

mlx_t	*address_mlx(mlx_t *mlx);
t_map	*address_map(t_map *map);

#endif