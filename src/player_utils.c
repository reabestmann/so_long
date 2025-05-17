/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:39:39 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/17 18:00:16 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_finished(t_game *game)
{
	ft_printf("You escaped in %d moves!\n", game->player.moves);
//	reward(); try on linux
	close_window(game);
}

static int	xy_pos(int key, int i)
{
	if (key == KEY_W || key == KEY_A)
		return (i - 1);
	if (key == KEY_S || key == KEY_D)
		return (i + 1);
	return (i);
}

void	move_player(t_game *game, int key)
{
	int	x;
	int	y;
	int	c;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (key == KEY_W || key == KEY_S)
		y = xy_pos(key, y);
	else
		x = xy_pos(key, x);
	c = game->map[y][x];
	if (c == '1' || (c == 'E' && collectibles_remaining(game)))
		return ;
	if (c == 'E' && !collectibles_remaining(game))
		game_finished(game);
	game->map[game->player.pos_y][game->player.pos_x] = '0';
	game->player.pos_y = y;
	game->player.pos_x = x;
	game->map[y][x] = 'P';
	if (c == 'C')
		collect_item(game, x, y);
	draw_map(game);
	game->player.moves++;
	ft_printf("Moves: %d ꒰ঌ₍ᐢ. .ᐢ₎໒꒱\n", game->player.moves);
}

int	handle_keypress(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_S
		|| key == KEY_A || key == KEY_D)
		move_player(game, key);
	else if (key == KEY_ESC)
		close_window(game);
	return (0);
}

void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.pos_x = x;
				game->player.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
