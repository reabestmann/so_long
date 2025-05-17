/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:39:21 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/17 18:03:37 by rbestman         ###   ########.fr       */
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

/* KEYPRESS for hooking keyboard with game */
# ifndef KEYPRESS
#  define KEYPRESS 2
# endif

/* different key & close window codes for linux & mac */
# ifdef __APPLE__
#  define CLOSE 17
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
# else
#  define CLOSE 33
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
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
typedef struct s_player
{
	void	*img;
	int		pos_x;
	int		pos_y;
	int		moves;
}	t_player;

typedef struct s_collectible
{
	void	*img;
	int		total;
	int		found;
}	t_collectible;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	void		*wall;
	void		*floor;
	void		*exit;
	t_collectible	collectible;
	t_player	player;
}	t_game;

/* get_next_line.c */
char	*get_next_line(int fd);
/* map_utils.c */
void	print_map(char **map); //for testing
void	reward(void);
char	**get_map(char *file);
int		map_height(char *file);
int		map_width(char *file);
void		free_array(char **map);
void		error(char *message);
/* window_utils.c */
void		init_window(t_game *game, int map_width, int map_height);
void		load_images(t_game *game);
void		draw_map(t_game *game);
int		close_window(t_game *game);
/* player_utils.c */
void		find_player(t_game *game);
int		handle_keypress(int key, t_game *game);
void		move_player(t_game *game, int key);
/* collectible_utils.c */
void		count_total(t_game *game);
int		collectibles_remaining(t_game *game);
void		collect_item(t_game *game, int x, int y);
#endif
