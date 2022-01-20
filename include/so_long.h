/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:58:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/01/20 10:44:55 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <OpenGL/gl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# ifndef BLOCK_SIZE
#  define BLOCK_SIZE 64
# endif

typedef struct s_game
{
	int		row;
	int		col;
	char	*path;
	char	**map;
	void	*mlx;
	void	*win;
}	t_game;

typedef struct s_image {
	void	*wall;
	void	*empty;
	void	*collect;
	void	*exit;
	void	*player;
}	t_image;

#endif