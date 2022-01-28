/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:51:39 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/28 17:19:14 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *game)
{
	int	i;

	if (game->img)
	{
		mlx_destroy_image(game->mlx, game->img->wall);
		mlx_destroy_image(game->mlx, game->img->empty);
		mlx_destroy_image(game->mlx, game->img->collect);
		mlx_destroy_image(game->mlx, game->img->exit);
		mlx_destroy_image(game->mlx, game->img->exit_opened);
		mlx_destroy_image(game->mlx, game->img->player);
		free(game->img);
	}
	if (game->path)
		free(game->path);
	if (game->map)
	{
		i = 0;
		while (game->map[i] && i < game->col)
			free(game->map[i++]);
		free(game->map);
	}
	if (game)
		free(game);
}

int	close_game_win_ctrl(t_game *game)
{
	if (mlx_destroy_window(game->mlx, game->win))
	{
		printf("Error\nDestroy window failed\n");
		free_all(game);
		exit(EXIT_FAILURE);
	}
	free_all(game);
	printf("Closed by win x button\n");
	exit(EXIT_SUCCESS);
}

int	close_game(t_game *game, const char *close_msg)
{
	if (mlx_destroy_window(game->mlx, game->win))
	{
		printf("Error\nDestroy window failed\n");
		free_all(game);
		exit(EXIT_FAILURE);
	}
	free_all(game);
	printf("%s\n", close_msg);
	exit(EXIT_SUCCESS);
}
