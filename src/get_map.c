/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:05:46 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/28 16:30:13 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long_structs.h"
#endif
#include "so_long.h"

static void	pec_valid(char **map)
{
	int	line;
	int	player;
	int	exit;
	int	item;

	player = 0;
	exit = 0;
	item = 0;
	line = 0;
	while (map[line])
	{
		if (ft_strchr(map[line], 'E'))
			exit++;
		if (ft_strchr(map[line], 'P'))
			player++;
		if (ft_strchr(map[line], 'C'))
			item++;
		line++;
	}
	if (exit != 1 || player != 1 || item == 0)
	{
		free_array(map);
		error("Map: Invalid number of P/E/C");
	}
}

static void	chars_valid(char **map, int width)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		if (((int)ft_strlen(map[y])) != width + 1)
		{
			free_array(map);
			error("Map: empty or invalid line");
		}
		x = 0;
		while (x < width)
		{
			if (!ft_strchr("01PEC", map[y][x]))
			{
				free_array(map);
				error("Map: Invalid characters");
			}
			x++;
		}
		y++;
	}
}

static void	walls_valid(char **map, int height, int width)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
		{
			free_array(map);
			error("Map: Not surrounded by walls");
		}
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
		{
			free_array(map);
			error("Map: Not surrounded by walls");
		}
		y++;
	}
}

static void	shape_valid(char **map, int expected_width)
{
	int	y;
	int	width;

	y = 0;
	while (map[y])
	{
		width = ft_strlen(map[y]);
		if (width != expected_width + 1)
		{
			free_array(map);
			error("Map: Invalid shape");
		}
		y++;
	}
}

char	**get_map(char *file)
{
	int		height;
	int		width;
	char	**map;

	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
		error("Invalid map: wrong file format");
	height = map_height(file);
	width = map_width(file);
	map = malloc_map(file, height);
	chars_valid(map, width);
	walls_valid(map, height, width);
	shape_valid(map, width);
	pec_valid(map);
	path_valid(map, height);
	return (map);
}
