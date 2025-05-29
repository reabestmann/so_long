/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:29:50 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/28 16:30:35 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long_structs.h"
#endif
#include "so_long.h"

static char	**dup_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int y, int x, char c)
{
	if (map[y][x] == '1' || map[y][x] == c || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, y + 1, x, c);
	flood_fill(map, y - 1, x, c);
	flood_fill(map, y, x + 1, c);
	flood_fill(map, y, x - 1, c);
}

static void	check_reachables(char **map, char c)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				free_array(map);
				error("Map: Path to item or exit blocked");
			}
			x++;
		}
		y++;
	}
}

static void	find_start(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	path_valid(char **map, int height)
{
	char	**copy;
	int		pos_x;
	int		pos_y;

	find_start(map, &pos_x, &pos_y);
	copy = dup_map(map, height);
	if (!copy)
		error("Map: Memory error (dup failed)");
	flood_fill(copy, pos_y, pos_x, 'E');
	check_reachables(copy, 'C');
	free_array(copy);
	copy = dup_map(map, height);
	flood_fill(copy, pos_y, pos_x, '1');
	check_reachables(copy, 'C');
	check_reachables(copy, 'E');
	free_array(copy);
}
