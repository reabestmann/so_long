/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:27:16 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/28 18:11:46 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "so_long.h"

void	load_item_img(t_game *game)
{
	int	w;
	int	h;

	game->item.img[0] = mlx_xpm_file_to_image(
			game->mlx, "textures/item.xpm", &w, &h);
	game->item.img[1] = mlx_xpm_file_to_image(
			game->mlx, "textures/item2.xpm", &w, &h);
	game->item.img[2] = mlx_xpm_file_to_image(
			game->mlx, "textures/item3.xpm", &w, &h);
	game->item.img[3] = mlx_xpm_file_to_image(
			game->mlx, "textures/item4.xpm", &w, &h);
	game->item.img[4] = mlx_xpm_file_to_image(
			game->mlx, "textures/item5.xpm", &w, &h);
	game->item.frames = 5;
}

void	destroy_item_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->item.frames)
	{
		if (game->item.img[i])
			mlx_destroy_image(game->mlx, game->item.img[i]);
		i++;
	}
}

int	animate(t_game *game)
{
	static int	i_count;

	i_count++;
	if (i_count >= 20)
	{
		game->frame_i++;
		if (game->frame_i >= game->item.frames)
			game->frame_i = 0;
		i_count = 0;
	}
	draw_map(game);
	return (0);
}

/*
int	animate(t_game *game)
{
	animate_item(game);
	draw_map(game);
	return (0);
}*/
