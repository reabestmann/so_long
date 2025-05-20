/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:39:21 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/20 14:12:12 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* included libraries */
# include "so_long_macros.h"
# include "so_long_structs.h"
# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "mlx.h"

/* get_next_line.c */
char	*get_next_line(int fd);
/* get_map.c */
char	**get_map(char *file);
/* validate_path.c */
void    path_valid(char **map, int height);
/* map_utils.c
void	print_map(char **map); //for testing */
char	**malloc_map(char *file, int height);
int		map_height(char *file);
int		map_width(char *file);
void	free_array(char **map);
void	error(char *message);
/* window_utils.c */
void	init_window(t_game *game, int map_width, int map_height);
void	load_images(t_game *game);
void	draw_map(t_game *game);
int		close_window(t_game *game);
/* player_utils.c */
void	find_player(t_game *game);
int		handle_keypress(int key, t_game *game);
void	move_player(t_game *game, int key);
/* item_utils.c */
void	count_total(t_game *game);
int		items_remaining(t_game *game);
void	collect_item(t_game *game, int x, int y);
#endif
