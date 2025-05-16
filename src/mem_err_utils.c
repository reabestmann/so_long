/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_err_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:38:32 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/16 14:47:47 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	perror(message);
	exit (1);
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	close_window(t_game *game)
{
	if (game->map)
		free_array(game->map);
	if (game->mlx)
	{
		mlx_destroy_image(game->mlx, game->floor);
		mlx_destroy_image(game->mlx, game->wall);
		mlx_destroy_image(game->mlx, game->player);
		mlx_destroy_image(game->mlx, game->exit);
		mlx_destroy_image(game->mlx, game->collectible);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
//              mlx_destroy_display_(game->mlx); add when on linux
	}
	exit (0);
	return (0);
}
