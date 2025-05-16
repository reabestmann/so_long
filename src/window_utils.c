/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:12:06 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/16 15:33:06 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Function that turns each .xpm file into an image */
void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(
			game->mlx, "textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(
			game->mlx, "textures/floor.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(
			game->mlx, "textures/player.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(
			game->mlx, "textures/exit.xpm", &w, &h);
	game->collectible = mlx_xpm_file_to_image(
			game->mlx, "textures/collectible.xpm", &w, &h);
}

/* Helper Function to put specified texture images into the window */
static void	put_images(t_game *game, int c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(
			game->mlx, game->window, game->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(
			game->mlx, game->window, game->floor, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(
			game->mlx, game->window, game->player, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(
			game->mlx, game->window, game->exit, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(
			game->mlx, game->window, game->collectible, x, y);
}

/* Function that creates the map inside the window line by line */
void	draw_map(t_game *game)
{
	int	y;
	int	x;
	int	pixel_x;
	int	pixel_y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			pixel_x = x * TILE_SIZE;
			pixel_y = y * TILE_SIZE;
			put_images(game, game->map[y][x], pixel_x, pixel_y);
			x++;
		}
		y++;
	}
}

/* Function that creates a new game window and starts it */
void	init_window(t_game *game, int map_width, int map_height)
{
	if (!map_width || !map_height)
		error("Invalid map");
	game->width = map_width * TILE_SIZE;
	game->height = map_height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		error("Error initiating MinilibX");
	game->window = mlx_new_window(
			game->mlx, game->width, game->height, "so_long");
	if (!game->window)
		error("Error creating Window");
}
