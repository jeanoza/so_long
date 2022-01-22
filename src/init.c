/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:28:48 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/22 20:29:29 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *game_init(char *path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game)
	{
		game->path = ft_strdup(path);
		game->map = malloc(sizeof(char *) * get_map_col(game));
		if (game->map)
		{
			parse_map(game);
			game->mlx = mlx_init();
			game->win = mlx_new_window(game->mlx, (game->row) * B_SIZE, (game->col) * B_SIZE, "test");
			return (game);
		}
	}
	perror("game init error");//FIXME:find better way for precise error (ex: strerror(int errno))....
	exit(EXIT_FAILURE);
}

void	image_init(t_game *game)
{
	int size;
	int size32;

	game->img = malloc(sizeof(t_image));
	if (game->img == NULL)
	{
		perror("image init error");//FIXME:find better error message with strerror or other...
		exit(EXIT_FAILURE);
	}
	size = B_SIZE;
	size32 = B_SIZE / 2;
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "./asset/images/stone.xpm", &size, &size);
	game->img->empty = mlx_xpm_file_to_image(game->mlx, "./asset/images/sea.xpm", &size, &size);
	game->img->collect = mlx_xpm_file_to_image(game->mlx, "./asset/images/key_32.xpm", &size32, &size32);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "./asset/images/trasor_key.xpm", &size, &size);
	game->img->exit_opened = mlx_xpm_file_to_image(game->mlx, "./asset/images/map.xpm", &size, &size);
	game->img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/pirate.xpm", &size, &size);
}
