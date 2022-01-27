/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:31:10 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/27 21:27:58 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eval_next_location(int code, t_game *game, int *x, int *y)
{
	*x = game->px;
	*y = game->py;
	if (code == KEY_LEFT || code == KEY_A)
		game->px -= 1;
	else if (code == KEY_RIGHT || code == KEY_D)
		game->px += 1;
	else if (code == KEY_DOWN || code == KEY_S)
		game->py += 1;
	else if (code == KEY_UP || code == KEY_W)
		game->py -= 1;
	if (game->map[game->py][game->px] == '1')
	{
		game->px = *x;
		game->py = *y;
	}
	if (game->map[game->py][game->px] == 'C')
		--game->num_collect;
}

int	manage_input_key(int code, t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	if (code == KEY_ESC)
		close_game(game, "Close by ESC", 0);
	else
		eval_next_location(code, game, &tmp_x, &tmp_y);
	if (game->map[game->py][game->px] == 'C' && game->num_collect == 0)
		game->exitable = 1;
	if (game->map[game->py][game->px] == 'E' && game->exitable == 1)
		close_game(game, "Goal found!!\nCongraturations!!\n", 0);
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
