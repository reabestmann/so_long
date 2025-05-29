/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:25:49 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/19 12:57:57 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	items_remaining(t_game *game)
{
	return (game->item.found < game->item.total);
}

void	collect_item(t_game *game, int x, int y)
{
	game->item.found++;
	game->map[y][x] = 'P';
	draw_map(game);
	ft_printf("You found %d", game->item.found);
	ft_printf(" of %d items! ૮ ྀིྀིྀིྀིྀི˶ᵔ ᵕ ᵔ˶ ྀིྀིྀིྀིྀིა \n",
		game->item.total);
}

void	count_total(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->item.total = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->item.total++;
			x++;
		}
		y++;
	}
	game->item.found = 0;
}
