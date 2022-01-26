/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:51:39 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/26 23:53:14 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game_win_ctrl(t_game *game)
{
	int	i;

	if (mlx_destroy_window(game->mlx, game->win))
	{
		printf("Error\nDestroy window failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game->col)
		free(game->map[i++]);
	free(game->map);
	free(game);
	printf("Closed by win x button\n");
	exit(EXIT_SUCCESS);
}

int	close_game(t_game *game, const char *close_msg)
{
	int	i;

	if (mlx_destroy_window(game->mlx, game->win))
	{
		printf("Error\nDestroy window failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game->col)
		free(game->map[i++]);
	free(game->map);
	free(game);
	printf("%s\n", close_msg);
	exit(EXIT_SUCCESS);
}

int	exit_malloc_error(const char *where, const char *var)
{
	printf("Error\n%s init failed : can't malloc `%s`\n", where, var);
	exit(EXIT_FAILURE);
}

int	exit_parse_map_error(char **map, int nth_y, int done, const char *msg)
{
	int	i;

	i = 0;
	while (i < nth_y)
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
