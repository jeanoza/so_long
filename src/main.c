/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:08:34 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/20 23:24:45 by kychoi           ###   ########.fr       */
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
int	parse_map(t_game *game)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(game->path, O_RDONLY);
	tmp = get_next_line(fd);
	i = 0;
	while (tmp)
	{
		(game->map)[i++] = ft_strndup_free(tmp, game->row);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	game_init(char *path, t_game *game)
{
	game->path = ft_strdup(path);
	game->map = malloc(sizeof(char *) * get_map_col(game));
	if (parse_map(game) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->row) * B_SIZE, (game->col) * B_SIZE, "test");
	return (EXIT_SUCCESS);
}

int	image_init(t_image *img, t_game *game)
{
	img->size64 = B_SIZE;
	img->size32 = B_SIZE / 2;
	img->wall = mlx_xpm_file_to_image(game->mlx,
			"./asset/images/stone.xpm", &img->size64, &img->size64);
	// img->empty = mlx_xpm_file_to_image(game->mlx, "./asset/images/tile00.xpm", &img->size64, &img->size64);
	img->empty = mlx_xpm_file_to_image(game->mlx, "./asset/images/sea.xpm", &img->size64, &img->size64);
	img->collect = mlx_xpm_file_to_image(game->mlx,
			"./asset/images/goldenball32.xpm", &img->size32, &img->size32);
	img->exit = mlx_xpm_file_to_image(game->mlx,
			"./asset/images/ladder.xpm", &img->size64, &img->size64);
	img->player = mlx_xpm_file_to_image(game->mlx,
			"./asset/images/ship64.xpm", &img->size64, &img->size64);
	return (EXIT_SUCCESS);
}

int	render(t_image *img, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->col)
	{
		j = 0;
		while (j < game->row)
		{
			mlx_put_image_to_window(game->mlx, game->win, img->empty, j * B_SIZE, i * B_SIZE);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, img->wall, j * B_SIZE, i * B_SIZE);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, img->empty, j * B_SIZE, i * B_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, img->collect, j * B_SIZE + B_SIZE / 4, i * B_SIZE + B_SIZE / 4);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, img->exit, j * B_SIZE, i * B_SIZE);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, img->player, j * B_SIZE, i * B_SIZE);
			++j;
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	*game;
	t_image *img;

	game = malloc(sizeof(t_game));
	if (game_init(av[1], game) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	img = malloc(sizeof(t_image));
	image_init(img, game);
	render(img, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
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