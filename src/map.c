/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:25:42 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/25 00:31:55 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		is_last;
	char	*tmp;

	is_last = 0;
	fd = open(game->path, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp && i < game->col)
	{
		if (i == game->col - 1)
			is_last = 1;
		printf("result:%d\n", validation_line(tmp, is_last, i));
		(game->map)[i++] = ft_strndup_free(tmp, game->row);
		tmp = get_next_line(fd);
	}
	close(fd);
}
