/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:51:39 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/28 13:25:32 by kychoi           ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	free_all(game);
	printf("Closed by win x button\n");
	exit(EXIT_SUCCESS);
}

// int	close_game(t_game *game, const char *close_msg, int exit_num)
int	close_game(t_game *game, const char *close_msg)
{
	if (mlx_destroy_window(game->mlx, game->win))
	{
		printf("Error\nDestroy window failed\n");
		exit(EXIT_FAILURE);
	}
	free_all(game);
	printf("%s\n", close_msg);
	exit(EXIT_SUCCESS);
}

int	exit_malloc_error(t_game *game, const char *where)
{
	if (game)
		free_all(game);
	printf("Error\nGame init failed : can't malloc `%s`\n", where);
	exit(EXIT_FAILURE);
}

int	exit_parse_map_error(char **map, int nth_y, int done, const char *msg)
{
	int	i;

	i = 0;
	while (i < nth_y && map[i])
		free(map[i++]);
	free(map);
	if (done)
		printf("Error\nwrong map: %s\n", msg);
	else
		printf("Error\nwrong map: %s (line: %d)\n", msg, nth_y + 1);
	exit(EXIT_FAILURE);
}

int	exit_empty_error(char *line)
{
	free(line);
	printf("Error\nEmpty line");
	exit(EXIT_FAILURE);
}
