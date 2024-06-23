/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-23 08:32:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2024-06-23 08:32:43 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_txtr	*load_textures(t_allocs **allocs)
{
	t_txtr	*textures;

	textures = (t_txtr *)malloc(sizeof(t_txtr));
	if (!textures)
		ft_error(ERR_IMG_LOAD, allocs);
	textures->floor = mlx_load_png(IMG_FLOOR);
	textures->player = mlx_load_png(IMG_PLAYER);
	textures->wall = mlx_load_png(IMG_WALL);
	textures->collectible = mlx_load_png(IMG_COLLECTIBLE);
	textures->exit = mlx_load_png(IMG_EXIT);
	if (!textures->floor || !textures->player || !textures->wall \
		|| !textures->collectible || !textures->exit)
		ft_error(ERR_IMG_LOAD, allocs);
	return (textures);
}

t_txtr	*ft_images(t_allocs **allocs, t_txtr *textures, mlx_t *mlx)
{
	static t_txtr	*img;

	if (!img)
	{
		img = (t_txtr *)malloc(sizeof(t_txtr));
		if (!img)
			ft_error(ERR_IMG_LOAD, allocs);
		mhandler_add(allocs, img, img);
		img->floor = mlx_texture_to_image(mlx, textures->floor);
		img->player = mlx_texture_to_image(mlx, textures->player);
		img->wall = mlx_texture_to_image(mlx, textures->wall);
		img->collectible = mlx_texture_to_image(mlx, textures->collectible);
		img->exit = mlx_texture_to_image(mlx, textures->exit);
		mlx_delete_texture(textures->floor);
		mlx_delete_texture(textures->player);
		mlx_delete_texture(textures->wall);
		mlx_delete_texture(textures->collectible);
		mlx_delete_texture(textures->exit);
		free(textures);
		if (!img->floor || !img->player || !img->wall \
			|| !img->collectible || !img->exit)
			ft_error(ERR_IMG_LOAD, allocs);
	}
	return (img);
}

int	display_cell(mlx_t *mlx, t_txtr *images, t_map *cell)
{
	int		xy[2];
	int		r_value;

	xy[0] = cell->xy[0] * 128;
	xy[1] = cell->xy[1] * 128;
	if (cell->content == WALL)
		r_value = mlx_image_to_window(mlx, images->wall, xy[0], xy[1]);
	else if (cell->content == FLOOR || cell->content == PLAYER)
		r_value = mlx_image_to_window(mlx, images->floor, xy[0], xy[1]);
	else if (cell->content == COLLECTIBLE)
		r_value = mlx_image_to_window(mlx, images->collectible, xy[0], xy[1]);
	else if (cell->content == EXIT)
		r_value = mlx_image_to_window(mlx, images->exit, xy[0], xy[1]);
	return (r_value);
}

/*
	Display the map with textures.
*/
void	display(mlx_t *mlx, t_txtr *images, t_map *map, t_allocs **allocs)
{
	t_map	*parser;
	t_map	*player_cell;

	parser = map;
	player_cell = player(map, 0);
	while (parser)
	{
		if (parser != player_cell && display_cell(mlx, images, parser) < 0)
			ft_error(ERR_IMG_LOAD, allocs);
		if (parser->right)
			parser = parser->right;
		else
		{
			while (parser && parser->left)
				parser = parser->left;
			parser = parser->down;
		}
	}
	display_player(mlx, images, player_cell);
}
