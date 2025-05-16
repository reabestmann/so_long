/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:21:12 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/16 14:36:45 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int params, char **argv)
{
	t_game	game;

	if (params == 2)
	{
		game.map = get_map(argv[1]);
		if (!game.map)
			return (1);
		init_window(&game, map_width(argv[1]), map_height(argv[1]));
		load_images(&game);
		draw_map(&game);
		mlx_hook(game.window, EVENT_CLOSE, 0, close_window, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	ft_printf("USAGE: ./so_long mapdir/mapfile\n");
	return (1);
}
