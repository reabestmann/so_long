/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:21:12 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/16 13:04:02 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int params, char **argv)
{
	char	**map;
	t_game	game;

	if (params == 2)
	{
		map = get_map(argv[1]);
		if (!map)
			return (1);
		init_window(&game, map_width(argv[1]), map_height(argv[1]));
		load_images(&game);
		draw_map(map, &game);
		mlx_loop(game.mlx);
		free_array(map);
		return (0);
	}
	ft_printf("USAGE: ./so_long mapdir/mapfile\n");
	return (1);
}
