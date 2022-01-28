/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:50:31 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/28 13:51:58 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_malloc_error(t_game *game, const char *where)
{
	if (game)
		free_all(game);
	printf("Error\nGame init failed : can't malloc `%s`\n", where);
	exit(EXIT_FAILURE);
}

int	exit_parse_map_error(t_game *game, int nth_y, int done, const char *msg)
{
	free_all(game);
	if (done)
		printf("Error\nwrong map: %s\n", msg);
	else
		printf("Error\nwrong map: %s (line: %d)\n", msg, nth_y + 1);
	exit(EXIT_FAILURE);
}

int	exit_empty_error(t_game *game)
{
	free_all(game);
	printf("Error\nEmpty line");
	exit(EXIT_FAILURE);
}
