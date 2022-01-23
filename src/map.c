/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:25:42 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/23 16:04:11 by kychoi           ###   ########.fr       */
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
	tmp = get_next_line(fd);
	game->row = ft_strlen(tmp) - 1;
	game->col = 0;
	while (tmp)
	{
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

	fd = open(game->path, O_RDONLY);
	if (fd == -1)
	{
		//FIXME:How can i get errno(error number) to use with strerror function???? manual??
		// perror(strerror(5));
		perror("Parsing error");
		exit(EXIT_FAILURE);
	}
	tmp = get_next_line(fd);
	i = 0;
	while (tmp)
	{
		(game->map)[i++] = ft_strndup_free(tmp, game->row);
		tmp = get_next_line(fd);
	}
	close(fd);
}
