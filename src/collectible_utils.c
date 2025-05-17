/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:25:49 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/17 16:56:49 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectibles_remaining(t_game *game)
{
	return (game->collectible.found < game->collectible.total);
}

void	collect_item(t_game *game, int x, int y)
{
	game->collectible.found++;
	game->map[y][x] = '0';
	ft_printf("You found %d", game->collectible.found);
	ft_printf(" of %d items! ૮ ྀིྀིྀིྀིྀི˶ᵔ ᵕ ᵔ˶ ྀིྀིྀིྀིྀིა \n", game->collectible.total);
}

void	count_total(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collectible.total = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->collectible.total++;
			x++;
		}
		y++;
	}
	game->collectible.found = 0;
}
