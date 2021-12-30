/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:34:41 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/30 18:48:54 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	void	*mlx;
	void	*win;

	(void)ac;
	(void)av;

	// fd = open(av[1], O_RDONLY);
	// close(fd);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 640, "hello");
	mlx_pixel_put(mlx, win, 50, 50, 0x00FFFFFF);
	mlx_loop(mlx);
	return (0);
}
// char	*str;
// while ((str = get_next_line(fd)) != NULL)
// 	printf("%s", str);