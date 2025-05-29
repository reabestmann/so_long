/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:05:06 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/28 16:31:03 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "so_long_bonus.h"
#else
# include "so_long_structs.h"
#endif
#include "so_long.h"

/* Function to print map (for testing)
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_putstr_fd(map[i++], 1);
}*/

/* Function to format error messages & exiting the program */
void	error(char *message)
{
	perror(message);
	exit (1);
}

/* Function to free memory used by map array after usage */
void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

/* Funtion to get the number of lines in .ber file */
int	map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	height = 0;
	if (fd < 0)
		error("Invalid map");
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

/* Function to get the number of columns in .ber file */
int	map_width(char *file)
{
	int		fd;
	int		width;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Invalid map");
	width = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n' || c == '\0')
			break ;
		width++;
	}
	close(fd);
	if (!width)
		return (-1);
	return (width);
}

/* Function to parse map into a 2D array */
char	**malloc_map(char *file, int height)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Invalid map");
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
