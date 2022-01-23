/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:31:10 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/23 23:44:46 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eval_next_location(int code, t_game *game, int *x, int *y)
{
	*x = game->px;
	*y = game->py;
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
		game->px = *x;
		game->py = *y;
	}
}

int	manage_input_key(int code, t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	if (code == 53)
		close_game(game, "Close by ESC");
	else
		eval_next_location(code, game, &tmp_x, &tmp_y);
	if (game->map[game->py][game->px] == 'C' && game->num_collect == 1)
		game->exitable = 1;
	if (game->map[game->py][game->px] == 'E' && game->exitable == 1)
		close_game(game, "Goal found!!\nCongraturations!!\n");
	if (game->map[game->py][game->px] != 'E')
	{
		if (game->px != tmp_x || game->py != tmp_y)
			printf("step:%d\n", ++game->step);
		game->map[tmp_y][tmp_x] = '0';
		game->map[game->py][game->px] = 'P';
	}
	render(game);
	return (EXIT_SUCCESS);
}
