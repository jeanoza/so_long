/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:34:41 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/31 17:57:51 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_add_back(t_map **alst, t_map *new)
{
	t_map	*tmp;

	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

static int	get_map_size(const char *path)
{
	int		fd;
	char	buffer[MAP_BUFFER_SIZE];
	int		size;

	fd = open(path, O_RDONLY);
	size = 0;
	while (read(fd, buffer, MAP_BUFFER_SIZE))
	{
		if (buffer[0] != '\n')
			++size;
	}
	close(fd);
	return (size);
}

static void	parse_map(t_map *map, const char *path)
{
	int		fd;
	int		i;
	size_t	len;
	char	*current_line;
	t_map	*tmp;

	fd = open(path, O_RDONLY);
	current_line = get_next_line(fd);
	len = ft_strlen(current_line);
	tmp = malloc(sizeof(*tmp));
	if (ft_strchr(current_line, '\n'))
		--len;

	printf("len:%d\n", len);
	while (current_line != NULL)
	{
		i = 0;
		while (current_line[i])
		{
			if (current_line[i] != '\n')
			{
				tmp->symbol = current_line[i];
				tmp->x = (i % len);
				tmp->y = (i / len);
				printf("i:%d\n", i);
				ft_map_add_back(&map, tmp);
			}
			++i;
		}
		// current_line = get_next_line(fd);
	}
	free(tmp);
}


int	main(int ac, char **av)
{
	int		map_size;
	t_map	*map;

	(void)ac;
	map_size = get_map_size(av[1]);
	printf("ms:%d\n", map_size);
	map = (t_map *)malloc(sizeof(t_map) * map_size);
	parse_map(map, av[1]);

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
