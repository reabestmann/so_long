/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:39:21 by rbestman          #+#    #+#             */
/*   Updated: 2025/05/13 18:20:38 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* get_next_line.c */
char	*get_next_line(int fd);

/* map_utils.c */
char	**get_map(char *file);
void	print_map(char **map);
void	free_array(char **map);

#endif
