/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:08:34 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/19 01:26:19 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @param {char *} path
 * @param {t_game *} game
 * @returns {int} col
 */
int	get_map_col(char *path, t_game *game)
{
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
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
int	parse_map(char *path, t_game *game)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(path, O_RDONLY);
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

int	main(int ac, char **av)
{
	t_game	*game;
	int		i;
	int		j;

	(void)ac;
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(char *) * get_map_col(av[1], game));
	if (parse_map(av[1], game) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->row) * BLOCK_SIZE, (game->col) * BLOCK_SIZE, "test");


	//img struct

	typedef struct s_img {
		void	*image;
		int		w;
		int		h;
	} t_img;
	
	t_img *img;

	img = malloc(sizeof(t_img));
	img->w = BLOCK_SIZE;
	img->h = BLOCK_SIZE;

	img->image = mlx_xpm_file_to_image(game->mlx, "./asset/images/stone.xpm", &img->w, &img->h);
	i = 0;
	while (i < game->col)
	{
		j = 0;
		while (j < game->row)
		{
			//TODO: Change struct {char, *func}
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, img->image, i * BLOCK_SIZE, j * BLOCK_SIZE);
				
			// else if (game->map[i][j] == '0');
			// else if (game->map[i][j] == 'C');
			// else if (game->map[i][j] == 'E');
			// else if (game->map[i][j] == 'P');
			++j;
		}
		++i;
	}
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