/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:30:11 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/23 19:08:05 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	switch_case_render(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		put_img(game, game->img->wall, x * B_SIZE, y * B_SIZE);
	else if (game->map[y][x] == '0')
		put_img(game, game->img->empty, x * B_SIZE, y * B_SIZE);
	else if (game->map[y][x] == 'C')
	{
		++game->num_collect;
		put_img(game, game->img->collect,
			x * B_SIZE + B_SIZE / 4, y * B_SIZE + B_SIZE / 4);
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->exitable)
			put_img(game, game->img->exit_opened, x * B_SIZE, y * B_SIZE);
		else
			put_img(game, game->img->exit, x * B_SIZE, y * B_SIZE);
	}
	else if (game->map[y][x] == 'P')
	{
		game->px = x;
		game->py = y;
		put_img(game, game->img->player, x * B_SIZE, y * B_SIZE);
	}
}

int	render(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	game->num_collect = 0;
	while (y < game->col)
	{
		x = 0;
		while (x < game->row)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img->empty, x * B_SIZE, y * B_SIZE);
			switch_case_render(game, x, y);
			++x;
		}
		++y;
	}
	printf("ntc:%d\n", game->num_collect);
	return (EXIT_SUCCESS);
}
