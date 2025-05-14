/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:12:06 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/14 17:52:21 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	perror(str);
	exit (1);
}

void    load_images(t_game *game);
void    draw_map(char **map, t_game *game);

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
