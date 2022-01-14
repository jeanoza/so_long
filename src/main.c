/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:08:34 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/14 15:07:35 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_col(char *path, t_game *game)
{
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	tmp = get_next_line(fd);
	game->row = ft_strlen(tmp);
	if (ft_strrchr(tmp, '\n'))
		game->row -= 1;
	game->col = 0;
	while (tmp)
	{
		tmp = get_next_line(fd);
		++(game->col);
	}
	close(fd);
	return (game->row * game->col);
}

// int	parse_map(char *path, t_game *game)

int	main(int ac, char **av)
{
	int		map_size;
	t_game	*game;
	int		fd;

	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(char *) * get_map_col(av[1], game));

	printf("row:%d col:%d\n",game->row, game->col);
	

	fd = open(av[1], O_RDONLY);
	close(fd);
	return (0);
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