/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:30:11 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/22 22:46:23 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			mlx_put_image_to_window(game->mlx, game->win, game->img->empty, x * B_SIZE, y * B_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img->wall, x * B_SIZE, y * B_SIZE);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img->empty, x * B_SIZE, y * B_SIZE);
			else if (game->map[y][x] == 'C')
			{
				++game->num_collect;
				mlx_put_image_to_window(game->mlx, game->win, game->img->collect, x * B_SIZE + B_SIZE / 4, y * B_SIZE + B_SIZE / 4);
			}
			else if (game->map[y][x] == 'E')
			{
				printf("exitable:%d\n", game->exitable);
				if (game->exitable)
					mlx_put_image_to_window(game->mlx, game->win, game->img->exit_opened, x * B_SIZE, y * B_SIZE);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->img->exit, x * B_SIZE, y * B_SIZE);
			}
			else if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
				mlx_put_image_to_window(game->mlx, game->win, game->img->player, x * B_SIZE, y * B_SIZE);
			}
			++x;
		}
		++y;
	}
	return (EXIT_SUCCESS);
}
