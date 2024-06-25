/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:14:07 by vsyutkin          #+#    #+#             */
/*   Updated: 2024/06/25 18:34:47 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
  Hook for MLX.
  Shows different messages in terminal, based on actions done in the game.
*/
void	ft_hook(void *map)
{
	notification(map);
}

/*
	This function stores and returns if argument is NULL, top left most cell.
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
	mlx_t	*mlx;	
	t_txtr	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Gulag simulator HD", true);
	img = ft_images(allocs, load_textures(allocs), mlx);
	mlx_set_setting(MLX_MAXIMIZED, true);
	if (!mlx)
		ft_error(ERR_MLX, allocs);
	(void)address_map(*map_grid);
	(void)address_mlx(mlx);
	display(mlx, img, *map_grid, allocs);
	if (!mlx_loop_hook(mlx, ft_hook, *map_grid))
		return (mlx_terminate(mlx), ft_error(ERR_MLX, allocs), EXIT_FAILURE);
	mlx_key_hook(mlx, &ft_mlx_key_hook, NULL);
	mlx_close_hook(mlx, close_window, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/*
  Declare chained list for elements with allocated memory.
  Declare chained list for map grid.
  Initialize both of them.
  Parse map.
  Print map in terminal.
  Render the game.
  Free all alocated elements.
  Finish the program.
*/
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
