/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:14:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/05/28 16:03:12 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Suggestion from copilot:
w	1. Read the map from the file
w	2. Check if the map is valid
w	3. Create a window
	4. Load images
	5. Draw the map
w	6. Handle the events
w	7. Close the window

								! IMPORTANT INFO !								!
When player meets collectible, collectible disappears.
When player meets exit without collecting all collectibles, player get's 
	notification that they have to collect all collectibles.
When player collects all collectibles and meets exit, player wins.
Player's position is stored via pointer on cell he's on.
One of the collectibles is Solzhenitsyn. When player collects it, 
	he gets a notification that he has found Solzhenitsyn.

When player tries to go into wall, he dies (bonus part only).


Sprite animations: 
smoke from chimney of guard home (it's door IS the exit for the player)
player loosing 'cuz they are eaten by prisoner. 

ARROW KEYS FOR MOVEMENT ARE ALLOWED

	The game is about GULAG. The player is a guard.
	The player has to catch all escaping prisoners. 
Prisoners == collectible. 
	THEY CAN MOVE.

	If the player catches hiding prisoner, the player dies. 
	If the player catches running away prisoner, 
the prisoner is caught (as collectible)
	The prisoner can hide only if they are fed 
(only 1 turn after leaving their cell).
	Number of collectibles = number of barracks. 
	Prisoners that successfully escaped are counted 
but do not making the player lose.

	Cells of the prisoners provide them unlimited food and hide ability.
	Player moves at least 2 times faster than prisoner 
(due to lack of quality food of prisoner).

running prisoner = 
hiding prisoner = has food and fork in hand.

Vision in corner: if on same row or column, visible.
Player's vision is about 2 cells in front and 1 cell everywhere else.
There is ONLY 1 TOWER GUARD, 
from wich the player can see from 3 to 5 cells around.
The guard tower is near the exit for prisoneers for freedom.
It takes at least 2 moves for prisoner to escape through exit, 
but only 1 move for player to quit the guard tower and catch the prisoner.

Player spawns at the bottom of the map. 
The prisoner exit is at the top of the map.
they player has exactly enough turns 
to catch the nearest to escape prisoneer before he escapes.
then can camp at guard tower and catch them all when they are passing by.
The barracks are rectangular, with height of 3 and have 2 ways in/out 
(on top and bottom).
all the escaping prisoners are spawned in the barracks, and move firstly 
from bottomst barrack to the top one, then from top to the exit.

////////////////////////////////////////////////////////////////////////////////

base game: 

collectible = only escaping prisoners, and they are not moving.

*/

// Exit the program as failure.
// static void	ft_error(void)
// {
// 	ft_printf("%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// Print the window width and height.
static void	ft_hook(void *map)
{
	notification(map);
}

/*
	This function stores and returns if argument is NULL t_map cell.
Used to store top left most cell.
*/
t_map	*address_map(t_map *map)
{
	static t_map	*address;

	if (map)
		address = map;
	return (address);
}

/*
	This function stores and returns if argument is NULL mlx_t instance.
*/
mlx_t	*address_mlx(mlx_t *mlx)
{
	static mlx_t	*address;

	if (mlx)
		address = mlx;
	return (address);
}

/* Codes with commentaries:

int	main(void)
{
	mlx_t*			mlx;
	mlx_image_t*	img;

	mlx = mlx_init(WIDTH, HEIGHT, "Gulag simulator", true);
	img = mlx_new_image(mlx, 256, 256);
	mlx_set_setting(MLX_MAXIMIZED, true);
	if (!mlx)
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}*/
int	ft_mlx(t_map **map_grid, t_allocs **allocs)
{
	mlx_t			*mlx;	
	mlx_image_t		*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Gulag simulator", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_set_setting(MLX_MAXIMIZED, true);
	if (!mlx)
		ft_error("Couldn't initialize mlx. Exiting.", allocs);
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop_hook(mlx, ft_hook, *map_grid);
	(void)address_map(*map_grid);
	(void)address_mlx(mlx);
	mlx_key_hook(mlx, &ft_mlx_key_hook, NULL);
	mlx_close_hook(mlx, close_window, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_allocs	*head_to_free;
	t_map		*head_map_grid;

	head_to_free = NULL;
	head_map_grid = NULL;
	map(argc, argv, &head_map_grid, &head_to_free);
	print_map(&head_map_grid);
	(void)ft_mlx(&head_map_grid, &head_to_free);
	mhandler_free_all(&head_to_free);
	return (EXIT_SUCCESS);
}
