/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:12:06 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/16 14:43:50 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
}

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
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, pixel_x, pixel_y);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->floor, pixel_x, pixel_y);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->player, pixel_x, pixel_y);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, pixel_x, pixel_y);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collectible, pixel_x, pixel_y);
			x++;
		}
		y++;
	}
}

void	init_window(t_game *game, int map_width, int map_height)
{
	if (!map_width || !map_height)
		error("Invalid map");
	game->width = map_width * TILE_SIZE;
	game->height = map_height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		error("Error initiating MinilibX");
	game->window = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->window)
		error("Error creating Window");
}
