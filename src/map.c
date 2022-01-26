/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:25:42 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/26 22:57:50 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Valid line conditions
 *	1. All border must be closed
 *		=> first line, list line, (1,y), (last,y)) = '1'
 *	2. 'P' and 'E' have to be only one
 *	3. At least one 'C'
 */
static int	validation_line(t_game *game, char *line, int y)
{
	int	x;

	if (ft_strlen(line) - 1 != game->row)
		exit_parse_map_error(game->map, y, 0,
			"All row length is not same");
	x = 0;
	while (x < game->row)
	{
		if ((line[x] != '1')
			&& (y == 0 || y == game->col - 1 || x == 0 || x == game->row - 1))
			exit_parse_map_error(game->map, y, 0,
				"All border must be closed");
		if (line[x] == 'P')
			game->num_player += 1;
		if (line[x] == 'E')
			game->num_exit += 1;
		if (line[x] == 'C')
			game->num_collect += 1;
		++x;
	}
	return (1);
}

/**
 * @param {char *} path
 * @param {t_game *} game
 * @returns {int} col
 */
int	get_map_col(t_game *game)
{
	int		fd;
	char	*tmp;

	fd = open(game->path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nRead map failed");
		exit(EXIT_FAILURE);
	}
	tmp = get_next_line(fd);
	game->row = ft_strlen(tmp) - 1;
	game->col = 0;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		++(game->col);
	}
	close(fd);
	return (game->col);
}

/**
 * @param {char *}
 * @param {t_game *}
 * @returns {EXIT_SUCCESS | EXIT_FAILURE}
 */
void	parse_map(t_game *game)
{
	int		fd;
	int		i;
	char	*tmp;

	game->num_player = 0;
	game->num_exit = 0;
	game->num_collect = 0;
	fd = open(game->path, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp && i < game->col)
	{
		if (validation_line(game, tmp, i))
			(game->map)[i++] = ft_strndup_free(tmp, game->row);
		tmp = get_next_line(fd);
	}
	if (game->num_exit != 1)
		exit_parse_map_error(game->map, i, 1, "No or too much Exit");
	if (game->num_player != 1)
		exit_parse_map_error(game->map, i, 1, "No or too much Player");
	if (game->num_collect < 1)
		exit_parse_map_error(game->map, i, 1, "No collect");
	close(fd);
}
