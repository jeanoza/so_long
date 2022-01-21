/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:08:34 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/21 02:23:25 by kyubongchoi      ###   ########.fr       */
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
	img->empty = mlx_xpm_file_to_image(game->mlx, "./asset/images/sea.xpm", &img->size64, &img->size64);
	img->collect = mlx_xpm_file_to_image(game->mlx, "./asset/images/cask_32.xpm", &img->size32, &img->size32);
	img->exit = mlx_xpm_file_to_image(game->mlx, "./asset/images/ladder.xpm", &img->size64, &img->size64);
	// img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/ship3.xpm", &img->size64, &img->size64);
	// img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/pirate.xpm", &img->size64, &img->size64);
	// img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/ship64.xpm", &img->size64, &img->size64);
	img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/sunny_64.xpm", &img->size64, &img->size64);
	// img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/shanks_64.xpm", &img->size64, &img->size64);
	// img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/turtle_ship_64.xpm", &img->size64, &img->size64);
	return (EXIT_SUCCESS);
}

int	render(t_image *img, t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->col)
	{
		x = 0;
		while (x < game->row)
		{
			mlx_put_image_to_window(game->mlx, game->win, img->empty, x * B_SIZE, y * B_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, img->wall, x * B_SIZE, y * B_SIZE);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, img->empty, x * B_SIZE, y * B_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, img->collect, x * B_SIZE + B_SIZE / 4, y * B_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, img->exit, x * B_SIZE, y * B_SIZE);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, img->player, x * B_SIZE, y * B_SIZE);
			++x;
		}
		++y;
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