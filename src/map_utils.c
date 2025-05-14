/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:05:06 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/14 11:36:53 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/* Function to print map (for testing) */
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_putstr_fd(map[i++], 1);
}

/* Funtion to get the number of lines in .ber file */
static int	map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	height = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

/* Function to parse map into a 2D array */
char	**get_map(char *file)
{
	char	**map;
	char	*line;
	int		height;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	height = map_height(file);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

/* Function to free memory after using map */
void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
