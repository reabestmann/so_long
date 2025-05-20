/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:10:25 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/20 14:20:22 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

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
	void	*img;
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
	void		*wall;
	void		*floor;
	void		*exit;
	t_item		item;
	t_player	player;
}	t_game;

#endif
