/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:58:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/01/23 19:58:12 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <OpenGL/gl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

//FIXME: verify if this library is necessary...
// # include <sys/errno.h> 
// # include <string.h>

# ifndef B_SIZE
#  define B_SIZE 64
# endif

# ifndef GAME_TITLE
#  define GAME_TITLE "so_long"
# endif

typedef struct s_image {
	void		*wall;
	void		*empty;
	void		*collect;
	void		*exit;
	void		*exit_opened;
	void		*player;
}	t_image;

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
	int		num_collect;
	int		exitable;
	int		step;
	t_image	*img;
}	t_game;

/* init.c */
t_game	*game_init(char *path);
void	image_init(t_game *game);
/* input.c */
int		manage_input_key(int code, t_game *game);
/* map.c */
int		get_map_col(t_game *game);
void	parse_map(t_game *game);
/* render.c */
int		render(t_game *game);
/* mlx_func*/
void	put_img(t_game *game, void *img, int x, int y);
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