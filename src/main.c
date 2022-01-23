/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:08:34 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/23 16:13:52 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	(void)ac;

	game = game_init(av[1]);
	image_init(game);
	render(game);
	mlx_key_hook(game->win, manage_input_key, game);
	mlx_loop(game->mlx);
	exit (EXIT_SUCCESS);
}
/* basic command
void	*mlx;
void	*win;
mlx = mlx_init();
win = mlx_new_window(mlx, 640, 640, "hello");
mlx_pixel_put(mlx, win, 50, 50, 0x00FFFFFF);
mlx_loop(mlx);
*/

/* gnl test
int	fd;
char	*tmp;

fd = open(av[1], O_RDONLY);
tmp = get_next_line(fd);
while (tmp)
{
	printf("%s", tmp);
	tmp = get_next_line(fd);
}
close(fd);
*/