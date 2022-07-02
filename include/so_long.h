/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:58:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/06/26 16:33:18 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// # include <OpenGL/gl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# define B_SIZE 64
# define GAME_TITLE "so_long"

# define EVENT_KEY_PRESS 2
/* window frame x btn control in mlx_hook to exit game*/
# define EVENT_EXIT_WIN 17

/* keyboard input to move player */
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_ESC 53

/* step pixel location to add */
# define STEP_PIX_Y 12

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
	int		num_player;
	int		num_exit;
	int		exitable;
	int		step;
	t_image	*img;
}	t_game;

/* init.c */
t_game	*init_game(char *path);
void	init_image(t_game *game);
/* input.c */
int		manage_input_key(int code, t_game *game);
/* map.c */
int		get_map_col(t_game *game);
void	parse_map(t_game *game);
/* render.c */
int		render(t_game *game);
/* mlx_func */
void	put_img(t_game *game, void *img, int x, int y);
void	*xpm_to_img(t_game *game, char *path);
void	*xpm_to_img32(t_game *game, char *path);
/* exit.c */
int		close_game_win_ctrl(t_game *game);
int		close_game(t_game *game, const char *close_msg);
void	free_all(t_game *game);
/* error.c */
int		exit_malloc_error(t_game *game, const char *where);
int		exit_parse_map_error(t_game *game,
			int nth_y, int done, const char *msg);
int		exit_empty_error(t_game *game);
#endif
