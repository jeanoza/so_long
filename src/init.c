/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:28:48 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/28 13:25:24 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(char *path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->path = NULL;
	game->map = NULL;
	if (game == NULL)
		exit_malloc_error(game, "game");
	game->path = ft_strdup(path);
	if (game->path == NULL)
		exit_malloc_error(game, "game->path");
	game->map = malloc(sizeof(char *) * get_map_col(game));
	if (game->map == NULL)
		exit_malloc_error(game, "game->map");
	parse_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->row) * B_SIZE,
			(game->col + 1) * B_SIZE, GAME_TITLE);
	game->exitable = 0;
	game->step = 0;
	return (game);
}

void	init_image(t_game *game)
{
	int	size;
	int	size32;

	game->img = NULL;
	game->img = malloc(sizeof(t_image));
	if (game->img == NULL)
		exit_malloc_error(game, "game->image");
	size = B_SIZE;
	size32 = B_SIZE / 2;
	game->img->wall = xpm_to_img(game, "./asset/images/stone.xpm");
	game->img->empty = xpm_to_img(game, "./asset/images/sea.xpm");
	game->img->collect = xpm_to_img32(game, "./asset/images/key_32.xpm");
	game->img->exit = xpm_to_img(game, "./asset/images/trasor_key.xpm");
	game->img->exit_opened = xpm_to_img(game, "./asset/images/map.xpm");
	game->img->player = xpm_to_img(game, "./asset/images/pirate.xpm");
}
