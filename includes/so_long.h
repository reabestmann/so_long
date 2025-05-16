/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:39:21 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/16 15:21:52 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* BUFFER for get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* TILE_SIZE for draw_window */
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

/* EVENT_CLOSE for closing the window safely */
# ifdef __APPLE__
#  define EVENT_CLOSE 17
# else
#  define EVENT_CLOSE 33
# endif

/* included libraries */
# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "mlx.h"

/* Struct for MLX */
typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_game;

/* get_next_line.c */
char	*get_next_line(int fd);
/* map_utils.c */
/* void	print_map(char **map) //for testing */
char	**get_map(char *file);
int		map_height(char *file);
int		map_width(char *file);
/* window_utils.c */
void	init_window(t_game *game, int map_width, int map_height);
void	load_images(t_game *game);
void	draw_map(t_game *game);
/* mem_err_utils.c */
void	error(char *message);
void	free_array(char **map);
int		close_window(t_game *game);
#endif
