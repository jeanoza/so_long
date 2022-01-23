/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:51:39 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/23 23:43:02 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game, char *close_msg)
{
	int	i;

	if (mlx_destroy_window(game->mlx, game->win))
	{
		printf("Error: destroy window\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	free(game->map);
	free(game);
	printf("%s\n", close_msg);
	exit(EXIT_SUCCESS);
}
