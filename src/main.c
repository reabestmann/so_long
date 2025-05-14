/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:21:12 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/14 11:03:03 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int params, char **argv)
{
	char	**map;

	if (params == 2)
	{
		map = get_map(argv[1]);
		if (!map)
			return (1);
		print_map(map);
		free_array(map);
		return (0);
	}
	ft_printf("USAGE: ./so_long mapdir/mapfile\n");
	return (1);
}
