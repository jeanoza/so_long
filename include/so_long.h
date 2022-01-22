/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:58:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/01/22 12:40:36 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <OpenGL/gl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# ifndef B_SIZE
#  define B_SIZE 64
# endif

typedef struct s_game
{
	int		row;
	int		col;
	char	*path;
	char	**map;
	void	*mlx;
	void	*win;
	int		px;
	int		py;
	void	*p_img;
	t_image	img;
}	t_game;

typedef struct s_image {
	void		*wall;
	void		*empty;
	void		*collect;
	void		*exit;
	void		*player;
	int			size;
	int			size32;
}	t_image;

#endif

//left = 123
//right = 124
//down = 125
//up = 126

//w = 13
//a = 0
//s = 1
//d = 2
//x = 7

//esc = 53
//cmd = 259