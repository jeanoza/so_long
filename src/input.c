/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:31:10 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/23 19:17:11 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	manage_input_key(int code, t_game *game)
{
	int	x;
	int	y;

	if (code == 53)
		exit(EXIT_SUCCESS);
	x = game->px;
	y = game->py;
	if (code == 123 || code == 0)
		game->px -= 1;
	else if (code == 124 || code == 2)
		game->px += 1;
	else if (code == 125 || code == 1)
		game->py += 1;
	else if (code == 126 || code == 13)
		game->py -= 1;
	if (game->map[game->py][game->px] == '1')
	{
		game->px = x;
		game->py = y;
	}
	else
	{
		if (game->map[game->py][game->px] == 'C' && game->num_collect == 1)
			game->exitable = 1;
		if (game->map[game->py][game->px] == 'E' && game->exitable == 1)
			exit(EXIT_SUCCESS);
		if (game->map[game->py][game->px] != 'E')
		{
			game->map[y][x] = '0';
			game->map[game->py][game->px] = 'P';
		}
	}
	render(game);
	return (EXIT_SUCCESS);
}
