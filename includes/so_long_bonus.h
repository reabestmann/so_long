/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:10:25 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/28 16:19:11 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long_macros.h"
/* Struct for MLX */
typedef struct s_player
{
	void	*img;
	int		pos_x;
	int		pos_y;
	int		moves;
}	t_player;

typedef struct s_item
{
	void	*img[5];
	int		frames;
	int		total;
	int		found;
}	t_item;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	int			frame_i;
	void		*exit;
	void		*floor;
	void		*wall;
	t_item		item;
	t_player	player;
}	t_game;

/* animate.c */
int	animate(t_game *game);
void	load_item_img(t_game *game);
void	destroy_item_img(t_game *game);

#endif
