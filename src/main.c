/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:08:34 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/22 17:51:25 by kychoi           ###   ########.fr       */
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
void	parse_map(t_game *game)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(game->path, O_RDONLY);
	if (fd == -1)
	{
		//FIXME:How can i get errno(error number) to use with strerror function???? manual??
		// perror(strerror(5));
		perror("Parsing error");
		exit(EXIT_FAILURE);
	}
	tmp = get_next_line(fd);
	i = 0;
	while (tmp)
	{
		(game->map)[i++] = ft_strndup_free(tmp, game->row);
		tmp = get_next_line(fd);
	}
	close(fd);
}

t_game *game_init(char *path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game)
	{
		game->path = ft_strdup(path);
		game->map = malloc(sizeof(char *) * get_map_col(game));
		if (game->map)
		{
			parse_map(game);
			game->mlx = mlx_init();
			game->win = mlx_new_window(game->mlx, (game->row) * B_SIZE, (game->col) * B_SIZE, "test");
			return (game);
		}
	}
	perror("game init error");//FIXME:find better way for precise error (ex: strerror(int errno))....
	exit(EXIT_FAILURE);
}

void	image_init(t_game *game)
{
	int size;
	int size32;

	game->img = malloc(sizeof(t_image));
	if (game->img == NULL)
	{
		perror("image init error");//FIXME:find better error message with strerror or other...
		exit(EXIT_FAILURE);
	}
	size = B_SIZE;
	size32 = B_SIZE / 2;
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "./asset/images/stone.xpm", &size, &size);
	game->img->empty = mlx_xpm_file_to_image(game->mlx, "./asset/images/sea.xpm", &size, &size);
	game->img->collect = mlx_xpm_file_to_image(game->mlx, "./asset/images/key_32.xpm", &size32, &size32);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "./asset/images/trasor_key.xpm", &size, &size);
	game->img->exit_opened = mlx_xpm_file_to_image(game->mlx, "./asset/images/map.xpm", &size, &size);
	game->img->player = mlx_xpm_file_to_image(game->mlx, "./asset/images/pirate.xpm", &size, &size);
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
		printf("location:%c(px:%d, py:%d)\n", game->map[game->py][game->px], game->px, game->py);
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

int	main(int ac, char **av)
{
	t_game	*game;

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