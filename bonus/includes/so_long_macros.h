/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_macros.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:04:26 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/20 23:36:06 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MACROS_H
# define SO_LONG_MACROS_H

/* BUFFER for get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* TILE_SIZE for draw_window */
# ifndef TILE_SIZE
#  define TILE_SIZE 60
# endif

/* KEYPRESS for hooking keyboard with game */
# ifndef KEYPRESS
#  define KEYPRESS 2
# endif

/* different key & close window codes for linux & mac */
# ifdef __APPLE__
#  define EVENT_CLOSE 17
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define EVENT_CLOSE 33
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

#endif
